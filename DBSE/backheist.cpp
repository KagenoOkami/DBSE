#include "defines.h"

__FILE__ __DATE__ __TIME__

#define FILELOCATION SL_HEIST

Entry message:
	USERNAME has started gathering @pointsname@ for the summoning of Syr Shin!

Max Point Text:
	You only have enough strength to carry @maxbet@ @pointsname@ to the summoning location @user@.

Entry Instructions:
	Type @command@ [x] to donate @pointsname@ to the ritual!

Late Entry:
	Sorry, @user@ but the ritual has already begun! Adding @pointsname@ now could ruin the whole thing!

Cooldown Entry:
	Space & Time can only sustain one summoning once in a while. Maybe wait @timeleft@ for the entropy of nature's chakra to settle.

Cooldown Over:
	Wolves howl as nature is ready for another summoning!

Game Levels:
	Level 1:
		The Summoning of an Omega of Syr Shin
	Level 1 max:
		10
	Level 2:
		The Summoning of an Gamma of Syr Shin
	Level 2 max:
		20
	Level 3:
		The Summoning of an Beta of Syr Shin
	Level 3 max:
		30
	Level 4:
		The Summoning of an Alpha of Syr Shin
	Level 4 max:
		40
	Level 5:
		The Summoning of of Syr Shin himself



	Next level entry messages
		Omega
		Level 2:
		Gamma
		Level 3:
		Beta
		Level 4:
		Alpha
		Level 5:
		Sir Shyn
		
	Game outcomes:
		start:
			Alright people! Make the final adjustments to your robes, check if you added all your @pointsname@, the summoning is about to begin!
		single user succes:
			@user@ had either exceptional luck, or exceptional skill! The ritual was a success and was rewarded with @winamount@ @pointsname@
		single user fail:
			Without the aid of his pack, @user@ failed the ritual! A wild surge occurs! !wildsurge
		results:
			-
			
	Success1 100:
		-
	Success 34-99:
		-
	Success 1-33:
		-
	Success 0:
		