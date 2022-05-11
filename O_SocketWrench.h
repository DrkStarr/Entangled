
! ---------------------------------------------------------------------------- !
!       SOCKET WRENCH. 05/07/18
!
  Movabl  socketWrench "socket wrench"
    with  name 'socket' 'wrench' 'pitted' 'pit' 'tool' 'grease' 'layer',
          after [;
              Drop, Insert:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementTubes || second == brokenTube) "It's too big to fit in there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that. You might need it.";
          ],
          before [;
              Buy:
                  if (self in player) "You already have that.";
              Insert:
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Examine, Search:
                  print "It's a quarter-inch socket wrench, pitted and scarred by an explosion";
                  if (self in basementWorkbench) ". This tool survived. Anything else, like a screwdriver, melted away.";
                  ".";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "The tool is covered in a layer of grease that brings with it an awful smell.";
              PutOn:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that. You might need it.";
              Give:
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~What would I even do with that?~";
                  }
                  if (second == theTavernNick) "~You think I'm into cars? I'm not taking that for trade.~";
                  if (second == alleyBarPhil) {
                      print "~I'm a bartender, not a mechanic";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) {
                      convenienceStore.turningToClerk = true;
                      "~I'm not trying to fix an engine. I want my science project to work.~";
                  }
                  if (second == alleyRentalNancy) {
                      if (alleyRentalNancy.askAboutBowling) alleyRentalNancy.dontKillAskAboutBowling = true;
                      alleyRentalNancy.askAboutBowling = true;
                      "~What are you even doing here? Are you going to bowl tonight or what?~";
                  }
                  if (second == gasStationJerry) "~I got my own tools. A lot cleaner than that beat-up old thing.~";
                  if (second == theTavernHarry) "~What am I going to do with that?~";
                  if (second == smallParkEddie) "~Don't need that. But if you're looking to help me out, maybe you have something to drink?~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~Only pain and suffering resides inside. It is an evil object. Remove it from my sight.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~You know. I don't like to get my hands dirty. You can keep it.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Show:
                  if (second == alleyBarPhil) {
                      print "~That's worthless. If you're looking for stuff like that head over to the junkyard";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~What? Are you a regular handy man or something?~";                   ! Yes - ~Forget I asked.~
                  if (second == gasStationJerry) "~Better not be ours,~ the attendant says, looking over at the car.";   ! No - ~Then why you carring junk around?~
                  if (second == theTavernNick) "~What are you going to do with that?~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == smallParkEddie) "~I don't care about that. Got anything to drink?~";
                  if (second == madameSorrasMadameSorra) {
                      if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                      madameSorrasMadameSorra.spiritsRestless = true;
                      "~One has suffered in its presence. Why show it? You make the spirits restless.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~Maybe Jerry would like it. You know, he's into cars and all that.~";
                  }
                  if (second == convenienceStoreKid) "The kid gives you the cold shoulder as he tries to deal with the clerk.";
                      if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                      if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Are you looking to buy? Because you're not impressing me.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              Pet:
                  "The wrench is covered in a light residue.";
              Remove:
                  <<Take self>>;
              ThrowAt:
                  if (self in player) {
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      "You might need that. Better hold onto it.";
                  }
              Touch:
                  "It's metal and has warmed up in your hands.";
              Eat, Taste:
                  "Covered in a thin layer of grease, it would never taste any good.";
              Push, Rub:
                  if (self in player) "You try to clean the tool with your shirt, but the layer of grease fails to come off.";
                  move self to player;
                  "(first taking the socket wrench)^
                  You try to clean the tool with your shirt, but the layer of grease fails to come off.";
          ];
