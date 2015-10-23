#ifndef __CSHPLUGINROTATE_H
#define __CSHPLUGINROTATE_H

#include <ShSDK/ShSDK.h>
#include <ShEngineExt/ShEngineExt.h>

class CShPluginRotate : public CShPlugin
{

public:
	
	struct SRotatingEntity
	{
		ShEntity2 * entity;
		float velocity;
	};

	// Constructor / Destructor
								CShPluginRotate				(const char * szName);
	virtual						~CShPluginRotate			(void);

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
	CShArray<SRotatingEntity> m_aRotatingEntities;
};

#endif // __CSHPLUGINROTATE_H