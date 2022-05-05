#include "0_DayZExpansion_AI_Preload/Common/DayZExpansion_AI_Defines.c"

class ExpansionPathPoint
{
	vector Position;
	Object Parent;

	int Flags;

	ExpansionNavMesh NavMesh;

	ExpansionPathPoint Next;

	vector GetPosition()
	{
		if (Parent)
		{
			vector transform[4];
			Parent.GetTransform(transform);

			return Position.Multiply4(transform);
		}

		return Position;
	}

	void OnParentUpdate()
	{
		if (Parent)
		{
			NavMesh = ExpansionNavMeshes.Get(Parent);

			if (!NavMesh)
			{
				Parent = null;
			}
		}

		if (Parent)
		{
			vector transform[4];
			Parent.GetTransform(transform);

			Position = Position.InvMultiply4(transform);
		}
		else
		{
			NavMesh = null;
		}
	}

	void UpdateFlags(ExpansionPathHandler handler)
	{
		float distance = 1.0;

		Flags = 0;
		Flags |= Sample(distance, PGPolyFlags.WALK);
		Flags |= Sample(distance, PGPolyFlags.DISABLED);
		Flags |= Sample(distance, PGPolyFlags.DOOR);
		Flags |= Sample(distance, PGPolyFlags.INSIDE);
		Flags |= Sample(distance, PGPolyFlags.SWIM);
		Flags |= Sample(distance, PGPolyFlags.SWIM_SEA);
		Flags |= Sample(distance, PGPolyFlags.LADDER);
		Flags |= Sample(distance, PGPolyFlags.JUMP_OVER);
		Flags |= Sample(distance, PGPolyFlags.JUMP_DOWN);
		Flags |= Sample(distance, PGPolyFlags.CLIMB);
		Flags |= Sample(distance, PGPolyFlags.CRAWL);
		Flags |= Sample(distance, PGPolyFlags.CROUCH);
		Flags |= Sample(distance, PGPolyFlags.UNREACHABLE);
	}

	int Sample(float distance, PGPolyFlags flag)
	{
		if (!Next)
		{
			return 0;
		}
		
		PGFilter filter = new PGFilter();
		filter.SetFlags(flag, PGPolyFlags.NONE, PGPolyFlags.NONE);
		
		filter.SetCost(PGAreaType.NONE, 10.0);
		filter.SetCost(PGAreaType.TERRAIN, 10.0);
		filter.SetCost(PGAreaType.DOOR_OPENED, 10.0);
		filter.SetCost(PGAreaType.DOOR_CLOSED, 10.0);
		filter.SetCost(PGAreaType.OBJECTS, 10.0);
		filter.SetCost(PGAreaType.BUILDING, 10.0);
		filter.SetCost(PGAreaType.ROADWAY, 10.0);
		filter.SetCost(PGAreaType.ROADWAY_BUILDING, 10.0);
		filter.SetCost(PGAreaType.LADDER, 10.0);
		filter.SetCost(PGAreaType.CRAWL, 10.0);
		filter.SetCost(PGAreaType.CROUCH, 10.0);
		filter.SetCost(PGAreaType.FENCE_WALL, 10.0);
		filter.SetCost(PGAreaType.JUMP, 10.0);
		
		vector direction = vector.Direction(Position, Next.Position).Normalized();
		
		vector p0 = Position - (direction * distance);
		vector p1 = Position + (direction * distance);
		vector hitPos;
		vector hitNor;
		
		bool hit = GetGame().GetWorld().GetAIWorld().RaycastNavMesh(p0, p1, filter, hitPos, hitNor);
				
		if (hit)
		{
			return flag;
		}

		return 0;
	}

	void Copy(ExpansionPathPoint other)
	{
		Position = other.Position;
		Parent = other.Parent;
		NavMesh = other.NavMesh;
	}

	void FindPath(ExpansionPathHandler pathFinding, inout array<vector> path)
	{
		vector transform[4];
		pathFinding.m_Unit.GetTransform(transform);
		
		FindPathFrom(transform[3], pathFinding, path);
	}

	void FindPathFrom(vector startPos, ExpansionPathHandler pathFinding, inout array<vector> path)
	{
		int i;
		
		if (Parent)
		{
			vector transform[4];
			Parent.GetTransform(transform);
			
			startPos = startPos.InvMultiply4(transform);

			NavMesh.FindPath(startPos, Position, pathFinding.m_PathFilter, path);
			
			for (i = 0; i < path.Count(); i++)
			{
				path[i] = path[i].Multiply4(transform);
			}
		}
		else
		{
			pathFinding.m_AIWorld.FindPath(startPos, Position, pathFinding.m_PathFilter, path);
		}
	}
};