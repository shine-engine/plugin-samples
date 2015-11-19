#include "Extension.h"

#include <ShSDK/ShSDK.h>

#include "../Rotate/CShPluginRotate.h"
#include "../Translate/CShPluginTranslate.h"

static CShPluginRotate plugin_rotate;
static CShPluginTranslate plugin_translate;

extern "C"
{

SAMPLE_EXTENSION_EXPORT void ExtensionInitialize(void)
{
	// Initialize the Rotate Plugin
	const CShIdentifier & topPoolIdentifier = CShPooledObjectManagerManager::GetInstance()->GetTopPoolIdentifier();
	plugin_rotate.Initialize(topPoolIdentifier);
	plugin_translate.Initialize(topPoolIdentifier);

	// Register the Rotate Plugin
	ShApplication::RegisterPlugin(&plugin_rotate);
	ShApplication::RegisterPlugin(&plugin_translate);
}

SAMPLE_EXTENSION_EXPORT void ExtensionRelease(void)
{
	// Release the Rotate Plugin
	plugin_rotate.Release();
	plugin_translate.Release();
}

}
