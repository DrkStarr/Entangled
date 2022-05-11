
! ---------------------------------------------------------------------------- !
!       POWER VACUUM TUBE. 09/24/17
!
  Movabl  vacuumTubeAmp
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
                      vacuumTubeAmp.&name-->3 = 'tubes';
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
                  if (second == junkYardTV) "The set is broken, and one tube isn't going to fix it.";
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "It doesn't fit in there, and you'd get the attention of the attendant.";
                  }
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "Oil from your hands has ruined the tube. It'll blow in time. The amp is done for.
                      Hopefully, the tube will hold long enough to fire up the machine.";
                  }
                  if (second == junkYardTV) "The television is torn up and busted. There's no way that one vacuum tube is going to repair it.";
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
                  if (self in theTavernMarshall) {
                      if (theTavernNick in theTavern)
                          "You can't see the vacuum tubes right now, but you know the back of the amp is full of them.";
                      if (theTavernMarshall.turned) {
                          if (SelfPlayer.onRiser) {
                          } else {
                              SelfPlayer.onRiser = true;
                              print "You step up on the riser. ";
                          }
                      } else {
                          theTavernMarshall.turned = true;
                          if (SelfPlayer.onRiser) {
                              print "You turn the half stack. ";
                          } else {
                              SelfPlayer.onRiser = true;
                              print "You step up on the riser turning the half stack. ";
                          }
                      }
                      "There are several vacuum tubes that run the amp. Any one of them would fix the machine.";
                  }
                  "This vacuum tube is pretty bulky. But maybe that scientist knew there would be a lot of them around.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "The tube has no smell even though it was in the bar.";
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
                      "Oil from your hands has ruined the tube. It'll blow in time. The amp is done for.
                      Hopefully, the tube will hold long enough to fire up the machine.";
                  }
                  if (second == junkYardTV) "The television is torn up and busted. There's no way that one vacuum tube is going to repair it.";
                  "You don't want to lose that.";
              Give:
                  if (self in basementTimeMachine) "You can't do that. It's already in the machine.";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                     "~Can't take trade-ins, and that's junk. We're not a pawn shop.~";
                  }
                  if (second == theTavernNick)
                      "It's too late. You've already ruined the tube by handling it. The tube should work for a short while,
                      but the oil has done its damage.";
                  if (second == alleyBarPhil) {
                      print "~You looking to trade 'cause that's not worth anything";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) {
                      convenienceStore.turningToClerk = true;
                      "~I already did a project on Transistor Theory. How's that going to help?~";
                  }
                  if (second == alleyRentalNancy) "~I have no use for that. I don't even know what it does. Like. I don't want it.~";
                  if (second == gasStationJerry) {
                      "~Hmm, a vacuum tube? Sorry. I don't have any use for it.~";
                  }
                  if (second == smallParkEddie) "~What would I do with that? You might as well keep it.~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~I know vhat you have done. Your evil ways show. Be gone.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Why does everyone want to embrace technology? We should embrace the Earth.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Pull, Remove, Take:
                  if (self in basementTimeMachine) "You've fixed that. It's already in the machine.";
                  if (self in theTavernMarshall) {
                      if (theTavernNick in theTavern)
                          "I wouldn't mess with that amp with the bartender here. He might take it personally.";
                  }
                  if (theTavernMarshall.removedVacuumTube == false) {
                      theTavernMarshall.removedVacuumTube = true;
                      move self to player;
                      score = score + 5;
                      vacuumTubeAmp.&name-->3 = 'ph000201';
                      move brokenTubeYard to junkYardTV;
                      give self ~pluralname;
                      if (theTavernMarshall.turned) {
                          if (SelfPlayer.onRiser) {
                          } else {
                              SelfPlayer.onRiser = true;
                              print "You step up on the riser. ";
                          }
                      } else {
                          theTavernMarshall.turned = true;
                          if (SelfPlayer.onRiser) {
                              print "You turn the half stack. ";
                          } else {
                              SelfPlayer.onRiser = true;
                              print "You step up on the riser turning the half stack. ";
                          }
                      }
                      brokenTube.&name-->2 = 'ph09784';
                      "Pulling on the largest tube, it takes a minute to get it out.";
                  }
                  "You already have that.";
              Rub:
                  if (self in player) {
                      if (SelfPlayer in theTavern) {
                          if (theTavernNick in theTavern) "Not with the bartender here.";
                          "The bartender could come back at any moment. Now, might not be a good time.";
                      }
                      "You wipe at the glass, but it's as clean as it's going to get. You'll never get all the oil off.";
                  }
                  if (self in theTavernMarshall) {
                      if (theTavernNick in theTavern)
                      "I wouldn't mess with that amp with the bartender here. He might take it personally.";
                  }
                  "You don't have that.";
              Touch:
                  if (self in player) {
                      if (SelfPlayer in theTavern) {
                          if (theTavernNick in theTavern) "Not with the bartender here.";
                          "The bartender could come back at any moment. Now, might not be a good time.";
                      }
                      "The glass is smooth to the touch. But you'll never get all the oil off.";
                  }
                  if (self in theTavernMarshall) {
                      if (theTavernNick in theTavern)
                          "I wouldn't mess with that amp with the bartender here. He might take it personally.";
                  }
                  "You don't have that.";
              PushDir, Push, Turn:
                  if (self in theTavernMarshall) {
                      if (theTavernNick in theTavern)
                          "I wouldn't mess with that amp with the bartender here. He might take it personally.";
                  }
                  "You don't need to do that.";
              Pet:
                  if (SelfPlayer in theTavern) {
                      if (theTavernNick in theTavern) "Not with the bartender here.";
                  }
                  "You feel nothing unexpected. The glass is smooth.";
              Show:
                  if (self in basementTimeMachine) "You can't do that. It's already in the machine.";
                  if (second == alleyBarPhil) "~And what are you going to do with that?~";
                  if (second == alleyRentalNancy) "~What is this Hee Haw time? Pawn your junk somewhere else.~";
                  if (second == gasStationJerry) "~Interesting, but I can't use it.~";
                  if (second == theTavernNick) "You better not - the bartender would be upset.";
                  if (second == smallParkEddie) "~What are you going to do with that tube? It looks worthless.~";
                  if (second == convenienceStoreKid) "The kid ignores you, continuing with his argument.";
                  if (second == madameSorrasMadameSorra) {
                      "~I see more than you know. Do you understand the life you have ruined?~";
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
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              SwitchOn, SwitchOff:
                  if (self in theTavernMarshall) {
                      if (theTavernNick in theTavern)
                          "I wouldn't mess with that amp with the bartender here. He might take it personally.";
                  }
                  "It doesn't work like that.";
              ThrowAt:
                  if (self in player) {
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      "You don't want to lose that.";
                  }
              Wave:
                  if (SelfPlayer in theTavern) {
                      if (theTavernNick in theTavern)
                          "You better not - the bartender would be upset.";
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
          giveToJerry;
