#define _ARMA_

class CfgPatches
{
	class BuilderItems_StaticItems_Expansion
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Structures_Signs"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class bldr_expansion_code_lock: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Basebuilding\Items\Codelock\CodeLock.p3d";
		physLayer = "item_small";
		carveNavmesh = 0;
		class AnimationSources
		{
			class camo
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Codelock
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class attach_fence
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class bldr_expansion_sea_chest: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\gear\camping\sea_chest.p3d";
	};
	class bldr_expansion_safe1: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Basebuilding\Safes\Safe_01\Safe_01.p3d";
	};
	class bldr_expansion_safe2: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Basebuilding\Safes\Safe_02\Safe_02.p3d";
	};
	class bldr_expansion_safe3: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Basebuilding\Safes\Safe_03\Safe_03.p3d";
	};
	class bldr_expansion_goldbar: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Gear\Traders\gold_bar.p3d";
		physLayer = "item_small";
		carveNavmesh = 0;
	};
	class bldr_expansion_silverbar: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Gear\Traders\silver_bar.p3d";
		physLayer = "item_small";
		carveNavmesh = 0;
	};
	class bldr_expansion_goldnugget: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Gear\Traders\nugget_gold.p3d";
		physLayer = "item_small";
		carveNavmesh = 0;
	};
	class bldr_expansion_silvernugget: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Gear\Traders\nugget_silver.p3d";
		physLayer = "item_small";
		carveNavmesh = 0;
	};
	class bldr_expansion_LMG: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\LMG\lmg.p3d";
	};
	class bldr_expansion_M32: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\MGL\M32.p3d";
	};
	class bldr_expansion_DesertEagle: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Pistols\DE\DE.p3d";
	};
	class bldr_expansion_M9: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Pistols\M9\M9.p3d";
	};
	class bldr_expansion_NFP: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Pistols\NFP\nfp.p3d";
	};
	class bldr_expansion_PR9: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Pistols\PR9\Pr9.p3d";
	};
	class bldr_expansion_G36: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Rifles\G36\G36.p3d";
	};
	class bldr_expansion_SCAR: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Rifles\SCAR\SCAR.p3d";
	};
	class bldr_expansion_M890Shotgun: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Shotguns\M890\M890.p3d";
	};
	class bldr_expansion_BenelliM4: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Shotguns\Remore\BenelliM4.p3d";
	};
	class bldr_expansion_SDASS: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\Shotguns\SDASS\SDASS.p3d";
	};
	class bldr_expansion_MPX: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\SMG\GTM\MPX.p3d";
	};
	class bldr_expansion_MP5: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\SMG\MP5\MP5.p3d";
	};
	class bldr_expansion_Kedr: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\SMG\P99\Kedr.p3d";
	};
	class bldr_expansion_Vector: HouseNoDestruct
	{
		scope = 1;
		model = "\DayZExpansion\Objects\Weapons\Firearms\SMG\Vector\Vector.p3d";
	};
};
