#include "CShPluginRotate.h"

BEGIN_DERIVED_CLASS(CShPluginRotate, CShPlugin)
	// ...
END_CLASS()

static CShIdentifier dataSetRotationIdentifier("rotation");

/**
 * Constructor
 */
CShPluginRotate::CShPluginRotate(void)
: CShPlugin(CShIdentifier("rotate"))
, m_levelIdentifier(GID(NULL))
{

}

/**
 * Destructor
 */
CShPluginRotate::~CShPluginRotate(void)
{

}

/**
 * Initialize
 */
bool CShPluginRotate::Initialize(const CShIdentifier & identifier)
{
	m_levelIdentifier = identifier;

	return(true);
}

/**
 * Release
 */
bool CShPluginRotate::Release(void)
{
	m_levelIdentifier = GID(NULL);

	return(true);
}

/**
 * Called when the plugin is started
 */
void CShPluginRotate::OnPlayStart(void)
{
	CShArray<ShEntity2*> aEntity;

	// Get Every Entity2 in the level
	ShEntity2::GetEntity2Array(m_levelIdentifier, aEntity);

	// Loop through every every Entity2
	int entityCount = aEntity.GetCount();
	for (int i = 0; i < entityCount; ++i)
	{
		SRotatingEntity elmt;
		elmt.entity = aEntity[i];

		// Loop through every DataSet
		int dataSetCount = ShEntity2::GetDataSetCount(elmt.entity);
		for (int i = 0; i < dataSetCount; ++i)
		{
			ShDataSet * pDataSet = ShEntity2::GetDataSet(elmt.entity, i);

			// Check this is a "rotation" DataSet
			const CShIdentifier & dataSetIdentifier = ShDataSet::GetDataSetIdentifier(pDataSet);
			if (dataSetIdentifier == dataSetRotationIdentifier)
			{
				// check count
				int count = ShDataSet::GetDataCount(pDataSet);
				SH_ASSERT(1 == count);

				// Get the velocity from the dataset
				ShDataSet::GetDataValue(pDataSet, 0, elmt.velocity);

				// Add the element in the array of entity to rotate
				m_aRotatingEntities.Add(elmt);
			}
		}
	}
}

/**
 * Called when the plugin is stopped
 */
void CShPluginRotate::OnPlayStop(void)
{
	m_aRotatingEntities.Empty();
}

/**
 * Called when the plugin is paused
 */
void CShPluginRotate::OnPlayPause(void)
{
	// nothing here
}

/**
 * Called when the plugin is resumed
 */
void CShPluginRotate::OnPlayResume(void)
{
	// nothing here
}

/**
 * Called before the engine updates itself
 */
void CShPluginRotate::OnPreUpdate(void)
{
	// nothing here
}

/**
 * Called after the engine updates itself
 */
void CShPluginRotate::OnPostUpdate(float dt)
{
	// Loop through every the array of entities to rotate
	int entityCount = m_aRotatingEntities.GetCount();
	for (int i = 0; i < entityCount; ++i)
	{
		SRotatingEntity & elmt = m_aRotatingEntities[i];
		ShEntity2::Rotate(elmt.entity, CShEulerAngles(0.0f, 0.0f, elmt.velocity * dt));
	}
}