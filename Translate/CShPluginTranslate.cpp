#include "CShPluginTranslate.h"

BEGIN_DERIVED_CLASS(CShPluginTranslate, CShPlugin)
	// ...
END_CLASS()

static CShIdentifier dataSetTranslateIdentifier("translation");

/**
 * Constructor
 */
CShPluginTranslate::CShPluginTranslate(const char * szName)
: CShPlugin(CShIdentifier(szName))
, m_levelIdentifier(GID(NULL))
{

}

/**
 * Destructor
 */
CShPluginTranslate::~CShPluginTranslate(void)
{

}

/**
 * Initialize
 */
bool CShPluginTranslate::Initialize(const CShIdentifier & identifier)
{
	m_levelIdentifier = identifier;

	return(true);
}

/**
 * Release
 */
bool CShPluginTranslate::Release(void)
{
	m_levelIdentifier = GID(NULL);

	return(true);
}

/**
 * Called when the plugin is started
 */
void CShPluginTranslate::OnPlayStart(void)
{
	CShArray<ShEntity2*> aEntity;

	// Get Every Entity2 in the level
	ShEntity2::GetEntity2Array(m_levelIdentifier, aEntity);

	// Loop through every every Entity2
	int entityCount = aEntity.GetCount();
	for (int i = 0; i < entityCount; ++i)
	{
		STranslatingEntity elmt;
		elmt.entity = aEntity[i];

		// Loop through every DataSet
		int dataSetCount = ShEntity2::GetDataSetCount(elmt.entity);
		for (int i = 0; i < dataSetCount; ++i)
		{
			ShDataSet * pDataSet = ShEntity2::GetDataSet(elmt.entity, i);

			// Check this is a "rotation" DataSet
			const CShIdentifier & dataSetIdentifier = ShDataSet::GetDataSetIdentifier(pDataSet);
			if (dataSetIdentifier == dataSetTranslateIdentifier)
			{
				// Get the velocity from the dataset
				ShDataSet::GetDataValue(pDataSet, 0, elmt.velocity);

				// Add the element in the array of entity to rotate
				m_aTranslatingEntities.Add(elmt);
			}
		}
	}
}

/**
 * Called when the plugin is stopped
 */
void CShPluginTranslate::OnPlayStop(void)
{
	m_aTranslatingEntities.Empty();
}

/**
 * Called when the plugin is paused
 */
void CShPluginTranslate::OnPlayPause(void)
{
	// nothing here
}

/**
 * Called when the plugin is resumed
 */
void CShPluginTranslate::OnPlayResume(void)
{
	// nothing here
}

/**
 * Called before the engine updates itself
 */
void CShPluginTranslate::OnPreUpdate(void)
{
	// nothing here
}

/**
 * Called after the engine updates itself
 */
void CShPluginTranslate::OnPostUpdate(float dt)
{
	// Loop through every the array of entities to rotate
	int entityCount = m_aTranslatingEntities.GetCount();
	for (int i = 0; i < entityCount; ++i)
	{
		STranslatingEntity & elmt = m_aTranslatingEntities[i];
		ShEntity2::Translate(elmt.entity, CShVector3(0.0f, elmt.velocity * dt, 0.0f));
	}
}