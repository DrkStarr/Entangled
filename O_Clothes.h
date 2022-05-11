
! ---------------------------------------------------------------------------- !
!       CLOTHES. 08/16/16
!
  Object  clothes
    with  name 'cloths' 'clothes' 'pants' 'loose' 'jeans' 'flannel' 'shirt' 'pocket' 'pockets',
          short_name "your clothes",
          before [;
              Attack:

              Buy:
                  "You already have that.";
              Disrobe, Remove:
                  "Thinking about streaking around here?";
              Give:
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
                  "(first removing your clothes)^
                  Thinking about streaking around here?";
              Wave:
                  "That's a little hard to do.";
              Rub, Touch:
                  "You add to the grease that is already there.";
              Examine, Search:
                  "You're wearing loose jeans and a flannel shirt. But they're dirty from work.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "They don't smell even though you had a long day at work.";
              Pet:
                  "Your clothes are matted. The dirt is worn in.";
              Show:
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
                  if (second == alleyBarPhil) {
                      if (basement.firstTime)
                          "~Sorry. I'm a little busy right now, trying to catch up,~ he says, fishing out another glass from the bin.";
                      "~You look fine. What about them?~";
                  }
                  if (second == alleyRentalNancy) "~Are you, like, that poor or are you just dressing down?~";
                  if (second == gasStationJerry) "~Pretty comfortable, hun?~";
                  if (second == theTavernNick) "~I guess you like 'em. Not my style.~";
                  if (second == theTavernHarry) "~You know what you can do with those? Don't you?~";
                  if (second == smallParkEddie) "~Not much better than mine. You sure you don't live out here?~";
                  if (second == madameSorrasMadameSorra) {
                      if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                      madameSorrasMadameSorra.spiritsRestless = true;
                      "~Why show such a thing? It is pointless. You make the spirits restless.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~Spiffy. I bet they're comfortable.~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Makes me think that you can't afford what's in here.~";
                  }
                  if (second == convenienceStoreKid) "The kid seems to chuckle to himself before turning back to the clerk.";
                  if (second == oldMadameSorra) "~Your clothes tell me a lot about you,~ she says, thinking to herself.";
                  if (second == convenienceStoreOldAmy) "~I like them, but I usually dress down.~";
                  if (second == mapleRoadTom) "~I got better clothes at home. I just don't like to wear them.~";
                  if (second == tattooShopNick) {
                      if (tattooShopNick.askNickClothes) tattooShopNick.dontKillAskNickClothes = true;
                      tattooShopNick.askNickClothes = true;
                      "~I guess you look comfortable but aren't you warm?~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
              Take:

              Wear:

              Eat:
                  return PlayerEatWatch();
          ],
    has   proper pluralname clothing worn container open;
