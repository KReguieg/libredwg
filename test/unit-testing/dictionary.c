#define DWG_TYPE DWG_TYPE_DICTIONARY
#include "common.c"

void
api_process (dwg_object *obj)
{
  int error;
  BITCODE_BL i, numitems;
  BITCODE_BS cloning;
  BITCODE_RC hard_owner;
  BITCODE_TV* texts;
  BITCODE_H *itemhandles, *hdls;
  BITCODE_RC cloning_r14;

  dwg_obj_dictionary *_obj = dwg_object_to_DICTIONARY (obj);

  CHK_ENTITY_TYPE (_obj, DICTIONARY, numitems, BL, numitems);
  CHK_ENTITY_TYPE (_obj, DICTIONARY, cloning, BS, cloning);
  CHK_ENTITY_TYPE (_obj, DICTIONARY, hard_owner, RC, hard_owner);
  if (!dwg_dynapi_entity_value (_obj, "DICTIONARY", "texts", &texts, NULL))
    fail ("DICTIONARY.texts");
  if (!dwg_dynapi_entity_value (_obj, "DICTIONARY", "itemhandles", &itemhandles, NULL))
    fail ("DICTIONARY.itemhandles");
  hdls = _obj->itemhandles;
  for (i = 0; i < numitems; i++)
    {
      ok ("DICTIONARY.texts[%d]: %s", i, texts[i]);
      if (hdls[i] == itemhandles[i])
        ok ("DICTIONARY.itemhandles[%d]: " FORMAT_REF, i, ARGS_REF (itemhandles[i]));
      else
        fail ("DICTIONARY.itemhandles[%d]: " FORMAT_REF, i, ARGS_REF (itemhandles[i]));
    }
  CHK_ENTITY_TYPE (_obj, DICTIONARY, cloning_r14, RC, cloning_r14);
}