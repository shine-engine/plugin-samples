#ifndef __CSHPLUGINTRANSLATE_H
#define __CSHPLUGINTRANSLATE_H

#include <ShSDK/ShSDK.h>
#include <ShEngineExt/ShEngineExt.h>

class CShPluginTranslate : public CShPlugin
{

public:
	
	struct STranslatingEntity
	{
		ShEntity2 * entity;
		float velocity;
	};

	// Constructor / Destructor
								CShPluginTranslate			(void);
	virtual						~CShPluginTranslate			(void);

	bool						Initialize					(const CShIdentifier & identifier);
	bool						Release						(void);

	virtual	void				OnPlayStart					(void);
	virtual	void				OnPlayStop					(void);
	virtual	void				OnPlayPause					(void);
	virtual	void				OnPlayResume				(void);

	virtual	void				OnPreUpdate					(void);
	virtual	void				OnPostUpdate				(float dt);

	DECLARE_VARIABLES();

private:

	CShIdentifier m_levelIdentifier;
	CShArray<STranslatingEntity> m_aTranslatingEntities;
};

#endif // __CSHPLUGINROTATE_H