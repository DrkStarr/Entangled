
! ---------------------------------------------------------------------------- !
!       CRYSTAL SHARD. 01/15/18
!
  Movabl  crystalShard "quartz shard"
    with  name 'crystal' 'shard' 'clear' 'quartz',
          after [;
              Drop, Insert:
                  if (second == basementTimeMachine || second == basementMetalArm) {
                      if (basementTimeMachine.removeBrokenCrystal == false) {
                          basementTimeMachine.removeBrokenCrystal = true;
                          remove dullCrystal;
                          if (basementGenerator.generatorOn) {
                              basementGenerator.generatorOn = false;
                              if (basementButton in basement) remove basementButton;
                              basementLights.&name-->0 = 'lights';
                              basementTimeMachine.&name-->10 = 'ph00501';
                              print "(first taking the dull crystal and shutting off the generator)";
                          } else {
                              print "(first taking the dull crystal)";
                          }
                          print "^You pull out the dull crystal from the metal arm, tossing it aside. It rolls out of sight under the large machine.^^";
                      }
                      if (basementGenerator.generatorOn) {
                          basementGenerator.generatorOn = false;
                          if (basementButton in basement) remove basementButton;
                          basementLights.&name-->0 = 'lights';
                          basementTimeMachine.&name-->10 = 'ph00501';
                          print "(first shutting off the generator)^";
                      }
                      move self to basementMetalArm;
                      basementTimeMachine.insertCrystalShard = true;
                      "Grabbing on to the metal arm, you force the crystal into place with your hands. It eventually snaps into the housing.";
                  }
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementTubes || second == brokenTube) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that.";
          ],
          before [;
              Buy:
                  if (self in player) "You already have that.";
              Insert:
                  if (self in basementTimeMachine || self in basementMetalArm) "You can't do that, it's already in the machine.";
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Examine, Search:
                  if (self in basementTimeMachine || self in basementMetalArm) "The shard sits in the arm's housing.";
                  if (artGallery.brokeCat) "It's a crystal shard, leftover when the curator broke the cat.";
                  if (SelfPlayer.droppedCrystalCat) "This crystal shard broke off when you dropped the statue.";
                  "This crystal shard broke off when you dropped the ball.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "The crystal doesn't give off a scent.";
              Rub:
                  "The shard is clean and clear. It should hold when you engage the machine.";
              PutOn:
                  if (second == basementTimeMachine || second == basementMetalArm) {
                      if (basementTimeMachine.removeBrokenCrystal == false) {
                          basementTimeMachine.removeBrokenCrystal = true;
                          remove dullCrystal;
                          if (basementGenerator.generatorOn) {
                              basementGenerator.generatorOn = false;
                              if (basementButton in basement) remove basementButton;
                              basementLights.&name-->0 = 'lights';
                              basementTimeMachine.&name-->10 = 'ph00501';
                              print "(first taking the dull crystal and shutting off the generator)";
                          } else {
                              print "(first taking the dull crystal)";
                          }
                          print "^You pull out the dull crystal from the metal arm, tossing it aside. It rolls out of sight under the large machine.^^";
                      }
                      if (basementGenerator.generatorOn) {
                          basementGenerator.generatorOn = false;
                          if (basementButton in basement) remove basementButton;
                          basementLights.&name-->0 = 'lights';
                          basementTimeMachine.&name-->10 = 'ph00501';
                          print "(first shutting off the generator)^";
                      }
                      move self to basementMetalArm;
                      basementTimeMachine.insertCrystalShard = true;
                      "Grabbing on to the metal arm, you force the crystal into place with your hands. It eventually snaps into the housing.";
                  }
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that.";
              Give:
                  if (self in basementTimeMachine || self in basementMetalArm) "You can't do that. It's already in the machine.";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~It's pretty. Thanks. But I don't need it.~";
                  }
                  if (second == theTavernNick) "~That's not worth a whole lot, maybe if it was intact.~";
                  if (second == convenienceStoreKid) "~Look. I'm not doing my next project on crystals. I did that three years ago and lost.~";
                  if (second == alleyBarPhil) {
                      print "~Sorry. I'm not into that whole new age thing";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~If it were diamond I'd take it.~";
                  if (second == gasStationJerry) "~You know I think my Mom has one of those. She mediates with the thing.~";
                  if (second == theTavernHarry) "~What am I going to do with that?~";
                  if (second == smallParkEddie) "~I don't want that, but if you have something to eat or drink I'll take it.~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~That is a dark thing you hold. But I see a glimmer of hope on the horizon.~";
                  if (second == artGallerySarah) {
                      if (artGallerySarah.seenCatBroken) "~Now you're going to give it back? What's wrong with you?~";
                      if (artGallerySarah.seenBallBroken) "~You just destroyed a priceless piece of art, and now you want to give it to me? You are something.~";
                      "~You keep it. Broken quartz is a bad luck charm around here.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Show:
                  if (self in basementTimeMachine || self in basementMetalArm) "You can't do that. It's already in the machine.";
                  if (second == convenienceStoreKid) "The kid snorts to himself, turning his back as he complains to the clerk.";
                  if (second == alleyBarPhil) "~Quartz, hun? You one of them new age people?~";
                  if (second == alleyRentalNancy) "~Interesting, but dull.~";
                  if (second == gasStationJerry) "~What? Are you one of those hippies. Don't see a lot of them anymore. My Mom's still one, but she's stuck in the 60s.~";
                  if (second == theTavernNick) "~Still looking to trade? Because that isn't going to get you squat.~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == smallParkEddie) "~Yeah. Crystals are all the rage, flipping new agers.~";
                  if (second == madameSorrasMadameSorra) {
                      if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                      madameSorrasMadameSorra.spiritsRestless = true;
                      "~Bad energies flow around that. You make the spirits restless.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      if(self.showAmy)"~What's so special about that?~";
                      self.showAmy = true;
                      "~Haven't seen that before. Is it special?~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (artGallerySarah.seenBallBroken) "~What should I even do with you? Breaking something like that. You think it's funny? Get out of here.~";
                      if (artGalleryStatue in artGalleryPedestal) "~That's pure quartz,~ she says looking over at the cat, ~where did you get that?~";
                      if (artGallerySarah.seenCatBroken) "~What? Are you a sadist? Please, get out of here.~";
                      "~Oh my god. What did you do to the cat?~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              Remove, Take:
                  if (self in basementTimeMachine || self in basementMetalArm) "You've fixed that. It's already in the machine.";
                  "You already have that.";
              Pull:
                  if (self in basementTimeMachine || self in basementMetalArm) "You've fixed that. It's already in the machine.";
                  "You don't need to do that.";
              PushDir, Push, Turn:
                  "You don't need to do that.";
              Pet, Touch:
                  "It's a bit jagged. You don't want to cut your fingers.";
              ThrowAt:
                  if (self in player) {
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "You don't want to lose that.";
                  }
              Eat, Taste:
                  "I wouldn't do that. It would go down like a razor blade.";
              Replace:
                  if (player in basement) {
                      if (basementTimeMachine.insertCrystalShard) "You've already replaced that.";
                      <<Insert self basementTimeMachine>>;
                  }
                  rfalse;
          ],
          showAmy false;
