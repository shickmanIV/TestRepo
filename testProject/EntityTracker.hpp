#pragma once

class GameEntity; //forward declaration

//Contains a static list used to keep track of every GameEntity object. 
class EntityTracker
{
public:
	GameEntity* operator[] (const int &index)
	{
		return entityList[index];
	}

	//Returns the number of entities being stored.
	int getSize()
	{
		return entityList.size();
	}

	//Add a GameEntity to the end of the list
	bool push_back(GameEntity *pNew)
	{
		entityList.push_back(pNew);
	}

	//Remove a specific entity from the list.
	bool remove(GameEntity* pEntity)
	{
		for (int i = 0; i < entityList.size(); i++)
		{
			//Check if the address of the given entity is stored in the list.
			if (pEntity == entityList[i])
			{
				//Remove the node containing the given address.
				entityList.erase(entityList.begin() + i);
				return true;
			}
		}
		return false;
	}

private:
	static std::vector<GameEntity*> entityList;
};