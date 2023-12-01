[eAIRegisterFaction(eAIFactionEast)]
class eAIFactionEast : eAIFaction
{
	void eAIFactionEast()
	{
		m_Loadout = "EastLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionEast)) return true;
		if (other.IsInherited(eAIFactionCivilian)) return true;
		return false;
	}
};
