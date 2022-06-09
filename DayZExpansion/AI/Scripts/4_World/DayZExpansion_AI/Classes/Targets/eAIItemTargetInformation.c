class eAIItemTargetInformation extends eAIEntityTargetInformation
{
	private ItemBase m_Item;

	void eAIItemTargetInformation(EntityAI target)
	{
		Class.CastTo(m_Item, target);
	}

	override float GetThreat(eAIBase ai = null)
	{
#ifdef EAI_TRACE
		auto trace = CF_Trace_1(this, "GetThreat").Add(ai);
#endif

		if (m_Item.GetHealth("", "") <= 0.0)
			return 0.0;

		if (ai)
		{
			if (ai.GetHumanInventory().GetEntityInHands() || ai.eAI_HasWeaponInInventory())
				return 0.0;

			if (m_Item.IsWeapon() || m_Item.Expansion_IsMeleeWeapon())
			{
				Weapon gun;
				if (Class.CastTo(gun, m_Item))
				{
					Magazine mag;

					//! Ignore guns we don't have ammo for so we don't keep picking up guns that we can't use
					if (!ai.eAI_HasAmmoForFirearm(gun, mag, false))
						return 0.0;
				}

				float distance = GetDistanceSq(ai);
				if (distance < 0.001)
					distance = 0.001;

				float q;
				if (m_Item.IsWeapon())
					q = 1000000;
				else
					q = 10000;

				return q / distance;
			}
		}

		return 0.0;
	}

	override bool ShouldRemove(eAIBase ai = null)
	{
#ifdef EAI_TRACE
		auto trace = CF_Trace_1(this, "ShouldRemove").Add(ai);
#endif

		if (!ai && m_Item.GetHealth("", "") <= 0.0)
		{
			return true;
		}
		else if (m_Item.GetHierarchyRootPlayer())
		{
			//! Has been picked up since we last saw it
			return true;
		}
		else if (ai && GetThreat(ai) <= 0.1)
		{
			return true;
		}

		return false;
	}
};