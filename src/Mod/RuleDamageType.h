/*
 * Copyright 2010-2015 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM_RULEDAMAGETYPE_H
#define	OPENXCOM_RULEDAMAGETYPE_H

#include <yaml-cpp/yaml.h>

namespace OpenXcom
{

enum ItemDamageType { DT_NONE, DT_AP, DT_IN, DT_HE, DT_LASER, DT_PLASMA, DT_STUN, DT_MELEE, DT_ACID, DT_SMOKE, DAMAGE_TYPES };
enum ItemDamageRandomType { DRT_DEFAULT, DRT_UFO, DRT_TFTD, DRT_FLAT, DRT_FIRE, DRT_NONE, DRT_UFO_WITH_TWO_DICE };

/**
 * Represents a specific damage type.
 * @sa Item
 * @sa RuleItem
 */
struct RuleDamageType
{
	/// Set fixed arena of effect radius.
	int FixRadius;
	/// Set what random range use when calculating damage.
	ItemDamageRandomType RandomType;
	/// Set what resistance on armor is used.
	ItemDamageType ResistType;
	/// Use fire calculation of radius and power.
	bool FireBlastCalc;
	/// Damage type ignore direction of attack.
	bool IgnoreDirection;
	/// Damage type do not cause self destruct explosion.
	bool IgnoreSelfDestruct;
	/// Damage type can do stun damage to big units.
	bool IgnorePainImmunity;
	/// Damage type don't cause morale lose form health damage.
	bool IgnoreNormalMoraleLose;
	/// Damage type do not move health to negative values.
	bool IgnoreOverKill;
	/// How much of armor is ignored.
	float ArmorEffectiveness;
	/// Conversion form power to max explosion radius.
	float RadiusEffectiveness;
	/// Reduction of explosion power per tile.
	float RadiusReduction;
	/// Threshold of fire creation
	int FireThreshold;
	/// Threshold of smoke creation
	int SmokeThreshold;

	/// Conversion form power to unit damage.
	float ToHealth;
	/// Conversion form power to unit armor damage.
	float ToArmor;
	/// Conversion form power to unit armor damage before applying armor protection.
	float ToArmorPre;
	/// Conversion form power to wound chance.
	float ToWound;
	/// Conversion form power to item damage.
	float ToItem;
	/// Conversion form power to tile damage.
	float ToTile;
	/// Conversion form power to stun level.
	float ToStun;
	/// Conversion form power to energy lose.
	float ToEnergy;
	/// Conversion form power to time units lose.
	float ToTime;
	/// Conversion form power to morale lose.
	float ToMorale;

	/// Default constructor.
	RuleDamageType();
	/// Calculate random value of damage.
	int getRandomDamage(int power) const;
	/// Do this damage type affect only one target
	bool isDirect() const;
	/// Loads item data from YAML.
	void load(const YAML::Node& node);
};

} //namespace OpenXcom

#endif	/* OPENXCOM_RULEDAMAGETYPE_H */

