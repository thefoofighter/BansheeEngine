#pragma once

#include "CmD3D9Prerequisites.h"
#include "CmGenericBuffer.h"

namespace CamelotEngine
{
	class CM_D3D9_EXPORT D3D9GenericBuffer : public GenericBuffer
	{
	public:
		D3D9GenericBuffer(UINT32 elementCount, UINT32 elementSize, GenericBufferType type, GpuBufferUsage usage, bool randomGpuWrite = false, bool useCounter = false);
        ~D3D9GenericBuffer();

		/**
		 * @copydoc GenericBuffer::lockImpl
		 */
		virtual void* lock(UINT32 offset, UINT32 length, GpuLockOptions options);

		/**
		 * @copydoc GenericBuffer::unlockImpl
		 */
		virtual void unlock();

		/**
		* @copydoc GenericBuffer::readData
		*/
        virtual void readData(UINT32 offset, UINT32 length, void* pDest);

		/**
		* @copydoc GenericBuffer::writeData
		*/
        virtual void writeData(UINT32 offset, UINT32 length, const void* pSource,
				bool discardWholeBuffer = false);

		/**
		* @copydoc GenericBuffer::copyData
		*/
		void copyData(GenericBuffer& srcBuffer, UINT32 srcOffset, 
			UINT32 dstOffset, UINT32 length, bool discardWholeBuffer = false);

	protected:
		virtual GenericBufferView* createView(UINT32 firstElement, UINT32 elementWidth, UINT32 numElements, bool randomGpuWrite);
		virtual void destroyView(GenericBufferView* view);
	};
}