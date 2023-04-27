//
//#include "ProjectileList.hpp"
//
//void ProjectileList::insertAtFront(Projectile* pNewData)
//{
//	ProjectileNode* pNode = pHead;
//
//	if (pHead == nullptr)
//	{
//		pHead = new ProjectileNode(pNewData);
//	}
//	else
//	{
//		while (pNode->getNext() != nullptr)
//		{
//			pNode = pNode->getNext();
//		}
//		pNode->setNext(new ProjectileNode(pNewData));
//	}
//}