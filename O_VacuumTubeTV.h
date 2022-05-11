
! ---------------------------------------------------------------------------- !
!       POWER VACUUM TUBE. 12/27/17
!
  Movabl  vacuumTubeTV "power vacuum tube"
    with  name 'power' 'vacuum' 'tube' 'tubes',
          short_name [;
              if (self in basementTimeMachine) {
                  print "power vacuum tubes";
                  rtrue;
              }
              print "power vacuum tube";
              rtrue;
          ],
          after [;
              Drop, Insert:
                  if (second == basementTimeMachine || second == basementTubes || second == brokenTube) {
                      if (basementTimeMachine.removeBrokenTube == false) {
                          basementTimeMachine.removeBrokenTube = true;
                          remove brokenTube;
                          if (basementGenerator.generatorOn) {
                              basementGenerator.generatorOn = false;
                              if (basementButton in basement) remove basementButton;
                              basementLights.&name-->0 = 'lights';
                              basementTimeMachine.&name-->10 = 'ph00501';
                              print "(first taking the broken vacuum tube and shutting off the generator)";
                          } else {
                              print "(first taking the broken vacuum tube)";
                          }
                          print "^You pull out the broken tube throwing it to the ground. It shatters on contact.^^";
                      }
                      move self to basementTimeMachine;
                      basementTimeMachine.insertVacuumTube = true;
                      vacuumTubeTV.&name-->3 = 'tubes';
                      remove basementTubes;
                      give self pluralname;
                      if (basementGenerator.generatorOn) {
                          basementGenerator.generatorOn = false;
                          if (basementButton in basement) remove basementButton;
                          basementLights.&name-->0 = 'lights';
                          basementTimeMachine.&name-->10 = 'ph00501';
                          print "(first shutting off the generator)^";
                      }
                      "Carefully you insert the vacuum tube. Pushing down on it, making sure it's seated in place.";
                  }
                  move self to player;
                  if (second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't fit in there.";
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "It doesn't fit in there, and you'd get the attention of the attendant.";
                  }
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      if (theTavernMarshall.turned) "There's already a good vacuum tube in it.";
                      if (SelfPlayer.onRiser == false) "You can't do that from here.";
                      "You can't see where that goes.";
                  }
                  if (second == junkYardTV) "You took it. Why put it back?";
                  "You don't want to lose that.";
          ],
          before [;
              Buy:
                  if (self in player) "You already have that.";
              Insert:
                  if (self in basementTimeMachine) "You can't do that. It's already in the machine.";
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Examine, Search:
                  if (self in basementTimeMachine) "All the vacuum tubes look to be in good working order.";
                  if (self in junkYardTV) "Several vacuum tubes run the television. Any one of them would fix the machine.";
                  "This vacuum tube is pretty bulky. But maybe that scientist knew there would be a lot of them around.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "The tube has no smell even though it has been left outside.";
              PutOn:
                  move self to player;
                  if (second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't fit in there.";
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "It doesn't fit in there, and you'd get the attention of the attendant.";
                  }
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      if (theTavernMarshall.turned) "There's already a good vacuum tube in it.";
                      if (SelfPlayer.onRiser == false) "You can't do that from here.";
                      "You can't see where that goes.";
                  }
                  if (second == junkYardTV) "You took it. Why put it back?";
                  "You don't want to lose that.";
              Give:
                  if (self in basementTimeMachine) "You can't do that. It's already in the machine.";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~Can't take trade-ins, and that's junk. We're not a pawn shop.~";
                  }
                  if (second == theTavernNick)
                      "~What am I going to do with that? My equipment over there rocks. I'm gonna hit it big someday. You'll see.~";
                  if (second == alleyBarPhil) {
                      print "~You looking to trade 'cause that's not worth piss";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~I have no use for that. I don't even know what it does. Like. I don't want it.~";
                  if (second == gasStationJerry) {
                      "~Hmm, a vacuum tube? Sorry. I don't have any use for it.~";
                  }
                  if (second == theTavernHarry) "~Where do you find that stuff. It's junk if you ask me.~";
                  if (second == smallParkEddie) "~What would I do with that? You might as well keep it.~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~You already made that choice. Now you must consider another.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Why does everyone want to embrace technology? We should embrace the Earth.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Pull, Remove, Take:
                  if (self in basementTimeMachine) "You've fixed that. It's already in the machine.";
                  if (junkYardTV.removedVacuumTube == false) {
                      junkYardTV.removedVacuumTube = true;
                      move self to player;
                      score = score + 5;
                      vacuumTubeTV.&name-->3 = 'ph000201';
                      brokenTube.&name-->2 = 'ph09784';
                      give self ~pluralname;
                      "Pulling on the largest tube, it takes a minute to get it out.";
                  }
                  "You already have that.";
              Pet:
                  "You feel nothing unexpected. The glass is smooth.";
              Rub:
                  if (self in player) {
                      "You wipe at the glass, but it's as clean as it's going to get. Hopefully, it should work.";
                  }
                  "You don't have that.";
              Touch:
                  if (self in player) {
                      "You touch the glass, but it's as clean as it's going to get. Hopefully, it should work.";
                  }
                  "You don't have that.";
              PushDir, Push, Turn:
                  "You don't need to do that.";
              Show:
                  if (self in basementTimeMachine) "You can't do that. It's already in the machine.";
                  if (second == alleyBarPhil) "~And what are you going to do with that?~";
                  if (second == alleyRentalNancy) "~What is this Hee Haw time? Pawn your junk somewhere else.~";
                  if (second == gasStationJerry) "~Interesting, but I can't use it.~";
                  if (second == theTavernNick) "~Look at that thing. Where did you find it?~ the bartender laughs to himself. ~I got better ones in my amp.~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == smallParkEddie) "~What are you going to do with that tube? It looks worthless.~";
                  if (second == madameSorrasMadameSorra) {
                      "~I see beyond vhat you have done. And I know you must be careful now.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~That's a piece of junk - do you travel around with a lot of stuff like that?~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~I'm not into materialism. We should follow Mother Gaia.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              SwitchOn, SwitchOff:
                  "It doesn't work like that.";
              ThrowAt:
                  if (self in player) {
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "You don't want to lose that.";
                  }
              Eat, Taste:
                  "The tube is a little big to fit into your mouth, and the glass would cut you to shreds.";
              Replace:
                  if (player in basement) {
                      if (basementTimeMachine.insertVacuumTube) "You've already replaced that.";
                      <<Insert self basementTimeMachine>>;
                  }
                  rfalse;
          ],
          giveToJerry false;
