
! ---------------------------------------------------------------------------- !
!       SPARK PLUG CAR. 06/07/17
!
  Movabl  sparkPlugCar "nickel spark plug"
    with  name 'nickel' 'spark' 'plug' 'fuse',
          after [;
              Drop, Insert:
                  if (second == basementGenerator) {
                      if (socketWrench in player) {
                          if (basementGenerator.removeFusedPlug == false) {
                              basementGenerator.removeFusedPlug = true;
                              remove fusedPlug;
                              print "(first taking the fused plug)
                              ^Using the socket wrench, you unscrew the spark plug. But when you pull it out of the
                              cylinder, it crumbles to dust in your hand.^^";
                          }
                          move self to basementGenerator;
                          basementGenerator.insertSparkPlug = true;
                          "You put the nickel plug into the cylinder, tightening it into place with the wrench.
                          If you're lucky, the generator should kick in now.";
                      } else {
                          move self to player;
                          "Without a wrench, you're not going to be able to tighten it in place.";
                      }
                  }
                  move self to player;
                  if (second == basementTubes || second == brokenTube) "It doesn't belong there.";
                  if (second == shedLawnMower) "You don't need to fix the mower. You better hold on to the part.";
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "You'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't fit in there.";
                  }
                  "You don't want to lose that.";
          ],
          before [;
              Buy:
                  if (self in player) "You already have that.";
                  if (self in gasStationCar) {
                      if  (gasStationJerry in gasStation) {
                          "You ask the attendant if he could sell you a spark plug.^
                          ^~Sorry. All the spare parts are locked up in the garage. The boss is the only one with a key.~";
                      }
                      "There's no one to sell it.";
                  }
              Insert:
                  if (self in basementGenerator) {
                      if (second == basementTimeMachine || second == basementMetalArm) "You can't do that. It's already in the generator.";
                  } else {
                      if (second == clothes) {
                          move self to player;
                          "You better hold on to that.";
                      }
                  }
              Examine, Search:
                  if (self in gasStationCar)
                      "The spark plug rests on the radiator. Carefully balanced, yet forgotten after a rushed clean up.";
                  if (self in basementGenerator) {
                      print "The plug sits inside the generator";
                      if (basementGenerator.generatorOn) ", with sparks firing to keep the machine running.";
                      ", ready to fire up.";
                  }
                  "The spark plug is almost pristine - the electrode gleaming in the light. The casing wiped clean.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "The plug has no smell even though it has been left outside.";
              PutOn:
                  move self to player;
                  if (second == shedLawnMower) "You don't need to fix the mower. You better hold on to the part.";
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "You'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't fit in there.";
                  }
                  "You don't want to lose that.";
              Give:
                  if (self in basementGenerator) "You can't do that. It's already in the generator.";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~I'm not into cars, but Jerry is. I know he's working on that Mercury over at the gas station. Maybe he could use it.~";
                  }
                  if (second == theTavernNick)
                      "~If you want to trade for something, it needs to have value. What am I going to do with that?~";
                  if (second == alleyBarPhil) {
                      print "~I can't take something like that, even if it works";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) {
                      convenienceStore.turningToClerk = true;
                      "~I already know about basic engineering. That's not going to help my project.~";
                  }
                  if (second == alleyRentalNancy) "~Like. I'm not a car person. You know.~";
                  if (second == gasStationJerry) "You better not - the attendant would be upset.";
                  if (second == theTavernHarry) "~What am I going to do with that?~";
                  if (second == smallParkEddie) "~Thanks. But you wouldn't have something a little more substantial. Like something to eat or drink? Would you?~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~You have stolen this, haven't you? I see it in your eyes.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Are you into cars or something? You should check out the junkyard.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Pull, Remove, Take:
                  if (self in basementGenerator) "The spark plug's in the generator and will keep it working.";
                  if (gasStationCar.removeSparkPlug == false) {
                      if (gasStationJerry in gasStation) {
                          gasStationJerry.eyesOpen = true;
                          if (gasStationComic in gasStation)
                              "The attendant looks up from the comic, seeing you step over to the car.
                              ~What do you think you're doing?~^^Thinking it over, you step back.";
                          "Stepping up to the car the attendant scolds you, ~what do you think you're doing?~^
                          ^Thinking it over, you step back.";
                      }
                      gasStationCar.removeSparkPlug = true;
                      move self to player;
                      remove sparkPlugMower;
                      score = score + 5;
                      "You take the spark plug before the attendant gets back.";
                  }
                  "You already have that.";
              Rub:
                  if (self in player) "You wipe at the casing a bit, but it's already clean.";
                  "You don't have that.";
              Touch:
                  "The plug is clean and smooth to the touch.";
              PushDir, Push, Turn:
                  "You don't need to do that.";
              Pet:
                  if (self in player) "You feel nothing unexpected.";
                  "You don't have that.";
              Show:
                  if (self in basementGenerator) "You can't do that. It's already in the generator.";
                  if (second == alleyBarPhil) {
                      print "~Not a lot of use for something like that around here";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) "The kid brushes you off.";
                  if (second == alleyRentalNancy) "~Are you a junk collector or something? Because it sure looks like it.~";
                  if (second == gasStationJerry) "You better not - the attendant would be upset.";
                  if (second == theTavernNick) "~Where did you steal that from?~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == smallParkEddie) "~If you're looking for something worthless, you should check out the junkyard.~";
                  if (second == madameSorrasMadameSorra) {
                  if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                      madameSorrasMadameSorra.spiritsRestless = true;
                      "~You do not see how things intertwine and have ruined another life. You make the spirits restless.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~Cars aren't my thing. You should show it to Jerry. He might want it.~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Holding on to any more junk?~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              SwitchOn, SwitchOff:
                  if (self in basementGenerator) <<SwitchOn basementGenerator>>;
                  "It doesn't work like that.";
              ThrowAt:
                  if (self in player) {
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      "You don't want to lose that.";
                  }
              Eat, Taste:
                  "You'd have a hard time getting that one down.";
              Replace:
                  if (player in basement) {
                      if (basementGenerator.insertSparkPlug) "You've already replaced that.";
                      <<Insert self basementGenerator>>;
                  }
                  rfalse;
          ];
