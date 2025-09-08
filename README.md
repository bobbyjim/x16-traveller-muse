# x16-traveller-muse
Modular Unstreamlined Starship Elements (MUSE)

# Top 7 Features for MUSE
* 1. "Oregon Trail" Goal

The goal of the game is for the player to outfit his ship in the Galaxiad era
to brave the long journey from Regina or Pretoria to Lobok or Vland -- and survive.
This gives the framework of exploration and purpose to the game.
Scoring depends on various factors in reaching the destination.

* 2. Ship Customization System

Core module management: bridge, thrusters, and modular add-ons.  The ship is a long
chain of modules identified by byte indexes into a table of characteristics.  

Vital for engaging the player in strategic planning and creative design.

* 2. Event Generation System

Randomized system events upon entering a star system: pirates, traders, aliens, or derelicts.
Essential for creating replayability and keeping the game loop dynamic and exciting.

* 3. Combat System

Narrative with basic diplomacy (trading insults or negotiating before fighting).
Adds tension and risk to exploration, requiring players to balance offense, defense, and ship upgrades.

* 4. Docking and Resupply System

Station interaction: refueling, repairs, upgrades, and trade.
Central to the player’s progression and survival.

* 6. Reputation System

Tracks player actions and consequences: diplomacy with factions, pirate behavior, and trade integrity.
Influences interactions, such as hostile encounters or discounted trade rates, adding depth to the sandbox.

* 7. Visual and Sound Effects System

Simple graphics for ships, events, and stations.
Retro sound effects for actions like docking, combat, and jumping.
Enhances immersion and ties together the retro aesthetic.

# The Flow

This game is about traveling from a safe region of space, through the dangerous Wilds,
to reach a far goal system, exploring, trading, and surviving as you go. As soon as you enter a star system, there's a pirate to fight off, or a trader to trade with, or an alien to try to interact with. 

Fast-paced and dynamic. The player is always engaged, dealing with new situations as soon as they jump into a new system. The event system keeps things fresh and exciting. Each system could have a "theme" or "event pool" to draw from, so that even though the events are random, they fit a narrative vibe.

# The Storyboards

## Map View
A simplified map view: the center is your current star, and then three or four tram lines extend outwards to your possible destination stars.  There’s no clutter, and no fuss: just your flight plan based on your next move.

As a step after resupply, it ties into the idea that, after all the action, the player takes a moment to plan and reconsider their next move. It feels very "in-character" for the journey itself, and it reinforces the feeling of being part of a larger, ongoing adventure.

* Each destination displays key information: distance, risk level, faction presence, or a vague hint about potential events (“Unstable Signals Detected” or “Frequent Trade Activity”), e.g.:
* A shield icon for patrol activity.
* A skull icon for high-risk systems (pirates or separatists).
* A glowing crate for trade opportunities.
* A swirl for alien activity or anomalies.

## Travel View 
This shows your ship in profile, arriving in system, or leaving it.

You might have interactions:
* Traders: Offer unique goods, trades, or questionable deals.
* Scouts: Provide intel on nearby systems or warnings.
* Aliens: Puzzles, communication challenges, or unexpected attacks.
* Patrol Vessels: Scan for contraband, enforce faction laws, or demand bribes.
* Hostiles: if diplomacy fails, then you progress to Combat View directly. ("Surrender your cargo, or we'll make space debris out of you!")

## Combat View
This is the Travel View with attackers there, and you interact by shooting at them and, if you have one, maneuvering the fighter.  

## Dock View
The Travel View with a space dock taking up one side of the screen, which shows your ship docked there.  Resupply, repair, upgrade/gear up, and then go along your merry way.

This is key! The idea of docking with a station not just for repairs but for upgrading and gearing up opens a lot of doors for customization. Perhaps there could be resource management involved, where players need to choose between saving money for a massive upgrade or buying consumables to prepare for an upcoming fight. It’ll add a layer of strategy to the game.

# Your Ship
Your ship is highly modular, so you can swap parts and add new ones easily and visibly to your ship -- including adding a little fighter or lander to expand your capabilities a bit.  The ship is also pretty blocky, which means graphics don't have to be too svelte.

This ties into the player's sense of ownership and agency over the journey. The ship's blocky design makes it easier to handle in terms of development, but also adds personality. It could become a central part of the game's narrative, where each new part added tells a story. The fighter/lander addition could make players feel like they’re preparing for a real adventure, with different gameplay elements based on their ship's configuration.

## Upgrades
Modules can be added by (a) purchase at a starport, (b) purchase from a trader, (c) looting from a space hulk

# Modules

There are 32 basic modules. All modules are rated on:

* CC = Command and Control
* CS  = Crew Stateroom
* CPU = Computer
* SEN = Sensor quality
* PS  = Passenger Stateroom
* LS  = Life Support
* M   = Maneuver
* J   = Jump
* C   = Cargo
* H   = Smuggler's Hatch
* F   = Fighter
* S   = Small craft (Cutter)
* T   = Turret
* D   = Defense

      ID  Type           Name               CC CPU SEN M J LS CS PS  C H F S T D
      $01 Bridge         Basic Bridge Plus   1  1   1  - -  -  5  -  - - - - - 1
      $02 Bridge         Full Bridge         3  2   2  - -  -  -  -  - - - - - 2
      $04 Bridge         Command Bridge      5  5   5  - -  -  -  -  - - - - - 3
      $05 Engine         Engine Room No. 1   -  -   -  1 1  5  -  -  - - - - - - 
      $06 Engine         Engine Room No. 2   -  -   -  1 2  -  -  -  - - - - - - 
      $07 Engine         Enhanced Jump       -  -   -  - 3  -  -  -  - - - - - - 
      $08 Engine         Fast Maneuver       -  -   -  5 -  -  -  -  - - - - - - 
      $09 Life Support   Life Support        -  -   -  - - 35  5  5  - - - - - -
      $0a Life Support   Living Cabins       -  -   -  - -  - 10 15  - - - - - -
	  $0b Life Support   Clinic              -  -   -  - -  -  -  -  - - - - - - 
      $0c Cargo          Cargo Pod           -  -   -  - -  -  -  -  1 - - - - -


* Bridge. Every starship must have one, and come at the front of every starship.
* Engine. Every starship must have one, and come at the end of every starship.
* Cargo Pod. Determines trade capacity.

## Add-On Enhancements
Every core module has one add-on slot. 

      ID  Type           Name               CC CPU SEN M J LS CS PS  C  H  F  S  T  D
	  $01 Screen         Screen              -  -   -  - -  -  -  -  -  -  -  -  - +1
	  $02 Weapon         Turret              -  -   -  - -  -  -  -  -  -  -  - +1  -
	  $03 Fighter        Fighter Bracket     -  -   -  - -  -  -  -  -  - +1  -  -  -
	  $04 Cutter         Cutter Bracket      -  -   -  - -  -  -  -  -  -  - +1  -  -
	  $05 Cargo          Small Cargo Pod     -  -   -  - -  -  -  - +1  -  -  -  -  -
	  $06 Cargo          Smuggler's Hatch    -  -   -  - -  -  -  -  - +1  -  -  -  -
	  $07 Sensor         Sensor Antenna      -  -  +1  - -  -  -  -  -  -  -  -  -  -


## Internal Structure

     struct Module {
         8 bits  : CoreModuleID      // base module type
		 5 bits  : Manufacturer
         3 bits  : Stage             // 
         3 bits  : Range             // another numeric modifier (e.g., +5% sensor range)
         3 bits  : Quality
         3 bits  : Efficiency
		 3 bits  : Reliability
		 3 bits  : Ergonomics
		 3 bits  : Safety
     }

## Manufacturer Database
	struct ManufacturerData {
		name : char[16];   // null terminated
		quality
		efficiency
		reliability
		ergonomics
		safety
	}

## Module Database Record Structure

	struct ModuleData {
		type    : 4 or 5 bits
			1 bridge / cpu / sensor
			2 engineering : jump / manuever
			3 life support / crew SR / pass SR
			4 cargo / smuggler hatch
			5 small craft : fighter / ship's boat
			6 weapon : beam laser / pulse laser / missile launcher / sandcaster / PA barbette
			7 defense : black globe / screens / dampers
		subtype        : 3 bits (see items under type)
		size           : 4 bits
		primaryValue   : 4 bits
		secondaryValue : 4 bits
		tertiaryValue  : 4 bits
	}

# The Map

The map is stored as sector-quadrants, four subsectors per quadrant.
* q1: a, b, e, f
* q2: c, d, g, h
* q3: i, j, m, n 
* q4: k, l, o, p

These sectors are encoded:
* SPIN - Spinward Marches
* DENE - Deneb
* CORR - Corridor
* VLAN - Vland

Thus there are 16 files, each with four subsectors.

Each quadrant file has this header:

   $000-$00f 	Sector full name, null padded.
   $010         #0
   $011         Quadrant number (0, 1, 2, 3)
   $012-$013 	Quadrant base coordinates.
   $014         Total system count. 255 is almost 80% capacity.
   $015-$6b7    Quadrant metadata. 	
   $6b8-$817 	System map.  0 = no system present.
   $818-$2000   System Records.

Quadrant Metadata. This is 1700 bytes of metadata for sundry purposes.

System Map. This is a 320 byte offset index, one for every hex in the quadrant.  If 
the index is 0, there is no system present.  Otherwise the system data is present at offset 32 x N, where N is the index from 1 to 255.

System Records. Up to 255 entries of data at 24 bytes each (about 79% full).

Each system record has a 24-byte structure:
   $00-$0b  Mainworld name, z-compressed.
   $0c-$0f  UWP, nybble-packed.
   $10-$11  Codes: 
   			2 bits: Bases, 
			2 bits: Zone, 
			1 bit: Belt presence, 
			1 bit: GG presence, 
			5 bits: Allegiance,
			4 bits: Importance.
   $12-$14  Remark flags: 24 remarks flags.
   $15-$18  Reserved
