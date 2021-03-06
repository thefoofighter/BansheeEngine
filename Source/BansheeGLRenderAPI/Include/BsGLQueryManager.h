//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#pragma once

#include "BsGLPrerequisites.h"
#include "BsQueryManager.h"

namespace BansheeEngine
{
	/** @addtogroup GL
	 *  @{
	 */

	/**	Handles creation and life of OpenGL queries. */
	class BS_RSGL_EXPORT GLQueryManager : public QueryManager
	{
	public:
		/** @copydoc QueryManager::createEventQuery */
		SPtr<EventQuery> createEventQuery() const override;

		/** @copydoc QueryManager::createTimerQuery */
		SPtr<TimerQuery> createTimerQuery() const override;

		/** @copydoc QueryManager::createOcclusionQuery */
		SPtr<OcclusionQuery> createOcclusionQuery(bool binary) const override;
	};

	/** @} */
}