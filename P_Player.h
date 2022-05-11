! ---------------------------------------------------------------------------- !
!       PLAYER. 08/09/16
!

  Object  SelfPlayer "self"
    with  short_name [; return L__M(##Miscellany, 18); ],
          name 'yourself',
          capacity MAX_CARRIED,
          description [;
              print "Dressed in jeans and a flannel shirt, they're the most comfortable things you own. ";
              if (self.outside == false) "But a little warm.";
              if (self.dayStart || self.preMorning || self.morningTime || self.dayTime) "But a little warm in the sun.";
              "They help to keep out the cold tonight.";
          ],
          each_turn [;
              iMinute++;
              ! The times are for October 10th / Location: Pittsburg - 6:48 Sunset - 7:27 Sunrise
              if (iHour == 6 && iMinute == 48 && iAMPM == 1) {
                  outsideLight.&name-->0 = 'street';
                  outsideLight.&name-->1 = 'light';
                  outsideLight.&name-->2 = 'streetlight';
                  outsideLight.&name-->3 = 'pole';
                  outsidePostOfficeLight.&name-->0 = 'street';
                  outsidePostOfficeLight.&name-->1 = 'light';
                  outsidePostOfficeLight.&name-->2 = 'streetlight';
                  outsidePostOfficeLight.&name-->3 = 'pole';
                  mapleRoadStreetLight.&name-->0 = 'streetlight';
                  mapleRoadStreetLight.&name-->1 = 'light';
                  mapleRoadStreetLight.&name-->2 = 'pole';
                  mapleRoadStreetLight.&name-->3 = 'street';
                  self.preEvening = false;
                  self.dayStart = false;
                  self.eveningTime = true;
                  livingRoomWindow.settingSun = false;
                  tattooShopNick.oldNickEveningTime = true;
                  cliffSun.&name-->4 = 'ph00256';
                  cliffSun.&name-->5 = 'ph00257';
                  cliffSun.&name-->6 = 'ph00258';
                  cliffSun.&name-->7 = 'ph00259';
                  if (self.outside) "^Night settles in as the last rays of the sun retreat.";
              }
              ! 7:04 on October 10th
              ! 7:46 Dark As Midnight
              if (iHour == 7 && iMinute == 16 && iAMPM == 1) {
                  self.nightTime = true;
                  self.earlyEvening = true;
                  self.eveningTime = false;
                  cliffSun.&name-->8 = 'ph00260';
                  cliffSun.&name-->9 = 'ph00261';
              }
              if (iHour == 7 && iMinute == 46 && iAMPM == 1) {
                  self.earlyEvening = false;
              }
              if (iHour == 6 && iMinute == 59 && iAMPM == 0) {
                  outsideLight.&name-->0 = 'ph005642';
                  self.nightTime = false;
                  self.preMorning = true;
                  if (self.outside) "^The first rays of a new sun light the sky.";
              }
              if (iHour == 7 && iMinute == 27 && iAMPM == 0) {
                  self.preMorning = false;
                  self.morningTime = true;
                  if (self.outside) "^The sun crests the horizon.";
              }
              if (iHour == 11 && iMinute == 59 && iAMPM == 0) {
                  self.morningTime = false;
                  self.dayTime = true;
              }
              if (iHour == 5 && iMinute == 10 && iAMPM == 1) {
                  self.dayTime = false;
                  self.preEvening = true;
                  if (self.outside) "^The sky changes color as evening approaches.";
              }
              if (iHour == 1 && iMinute == 45 && iAMPM == 0) {
                  if (self in theTavern) {
                      if (theTavernNick in theTavern) "^The bartender says, ~last call,~ signaling that it's time for you to leave.";
                      "^The bartender shouts from the back, ~last call,~ signaling that it's time for you to leave.";
                  }
              }
              if (iHour == iHourHarryLeaves && iMinute == 50) {
                  if (theTavernHarry in theTavern) {
                      move theTavernHarry to outsideJoesBar;
                      StartDaemon(theTavernHarry);
                      theTavernNick.harryLeftOnOwn = true;
                      theTavernHarry.pissedOff = true;
                      theTavernObj.advanceNick = true;
                      remove outsideJoesBarPerson;
                      remove theTavernDrink;
                      theTavernBooze.&name-->6 = 'drink';
                      if (self in theTavern) {
                          "^~Thanks, Nick. It's been great drinking with ya.~
                          ^^With that, the old guy slams down some cash and walks out of the bar.";
                      }
                      if (self in outsideJoesBar) {
                          "^The old guy talking at the bar slams down some cash and walks out of the place.
                          ^^He grunts a little when he notices you.";
                      }
                  }
              }
              if (self.startMoveJerry) {
                  if (iMinute == 50) {
                      remove gasStationJerry;
                      if (self in gasStation) {
                          self.sawJerryLeave = true;
                          "^~I have to go so bad I can feel my back teeth floating.
                          I need to use the pisser,~ says the attendant. Locking up the
                          booth, he walks over to the bathroom and vanishes behind the door.";
                      }
                  }
                  if (iMinute == 1) {
                      if (gasStationJerry in gasStation) {} else {
                          move gasStationJerry to gasStation;
                          gasStationBathroom.knockBathroom = false;
                          if (self in gasStation) {
                              if (self.sawJerryLeave) {
                                  print "^~Thanks for";
                              } else {
                                  print "^~Sorry to keep you";
                              }
                              " waiting,~ the attendant says as he leaves the bathroom. Grabbing another
                              soda, he gets back into the booth, locking the door behind him.";
                          }
                      }
                  }
              }
              if (iMinute == 60) {
                  iMinute = 0;
                  if (iHour == 12) iHour=0;
                  iHour++;
                  if (iHour == 12 && iAMPM == 0) {
                      iAMPM=1;
                  } else {
                      if (iHour == 12 && iAMPM == 1) iAMPM=0;
                  }
                  if (iHour == 2 && iMinute == 0 && iAMPM == 0) {
                      theTavern.closedUp = true;
                      if (self in outsideJoesBar) {
                          print "^The bartender waves to you as he locks the door and walks out. The music stops before he leaves.^";
                      }
                      if (self in theTavern) {
                          if (theTavernNick in theTavern) print "^The bartender says";
                          else print "^The bartender comes out from the back";
                          print ", ~that's it. The bars closed. Have a good night.~^
                          ^With that he locks you out of the bar.^";
                          if (watch.turnedOn) print "^A light beep rings from your watch.^";
                          PlayerTo(outsideJoesBar);
                          rtrue;
                      }
                  }
                  if (iHour == 8 && iMinute == 0 && iAMPM == 0) {
                      theTavern.closedUp = false;
                      if (self in outsideJoesBar) {
                          print "^You hear the door unlock to the bar and a moment later the music starts up.^";
                      }
                  }
                  if (iHour == 10 && iMinute == 0 && iAMPM == 1) {
                      if (convenienceStoreKid in convenienceStore) {
                          give convenienceStoreAmy ~scenery;
                          StopDaemon(convenienceStore);
                          remove convenienceStoreKid;
                          if (self in convenienceStore) {
                              convenienceStore.walkIn = false;
                              move convenienceStoreMelGone to convenienceStore;
                              print "^The kid looks down at his watch, ~Damn, I gotta get home.
                              This isn't over, Amy. I'll be back tomorrow.~^
                              ^The clerk addresses you as the kid rushes out the door. ~Wow, that was
                              starting to drive me crazy.~ Taking a second, she wipes off a bit of sweat
                              and then returns to her comic book.^";
                          }
                          if (self in outsideStore) {
                              print "^A kid steps out of the convenience store, snorting to himself when he sees you.
                              Then he takes off down the street running south.^";
                          }
                      }
                  }
                  if (watch.turnedOn) "^A light beep rings from your watch.";
              }
          ],
          before [;
              Attack:
                  if (player in cliff) <<Enter cliffObj>>;
              Pet, Play, Rub, Touch:
                  "This might not be the right time to do that sort of thing.";
              Push, Pull, Turn, PushDir, Take:
                  "What are you even trying to do?";
              Eat:
                  "Really?";
              Kiss:
                  "That's a little strange. Maybe you shouldn't.";
              Talk:
                  "Do you usually go around mumbling things?";
              WakeOther:
                  <<Wake location>>;
              WaveObject:
                  "You look strange doing that.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "You don't smell. You took a shower this morning.";
          ],
          life [;
              Answer, Ask, AskTo, AskCreatureFor:
                  "Do you usually go around mumbling things?";
          ],
          onRiser false,
          outside true,
          eveningTime false,
          morningTime false,
          nightTime false,
          dayStart true,
          dayTime false,
          preEvening false,
          preMorning false,
          kidsGone false,      ! Read this value at the end of the game to see if the player scared the kids away
          kidsRunAway false,
          knowAmy false,
          knowJerry false,
          knowMark false,
          knowNancy false,
          knowNick false,
          knowPhil false,
          knowSorra false,
          knowHarry false,
          knowEddie false,
          knowSarah false,
          knowTom false,
          scoredTom false,
          droppedCrystalBall false,
          droppedCrystalCat false,
          startMoveJerry false,
          sawJerryLeave false,
          gaveEddieDollar false,
          earlyEvening false,
    has   animate concealed proper;

! 10/11/2018
! Object is in global scope, player can access it anywhere

  Object  playerHands
    with  name 'hands' 'hand' 'palm',
          short_name "your hands",
          before [;
              Examine, Search:
                  "Your hands look rugged even though you've always looked young for your age.";
              Rub:
                  if (InventEmpty()) {
                      if (self.handsStink) "You rub your hands together for a minute, but the smell won't go away.";
                      if (basementWalls.tryToClean) "You rub your hands together for a minute, but the grease won't come off.";
                      "You rub your hands together for a minute.";
                  }
                  if (babushka in player) "It would be rude to clean your hands with the scarf. You shouldn't have reached into the dumpster.";
                  "You have stuff in your hands.";
              Show:
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~Yeah. I can see you have my incense. Now try returning it.~";
                      if (InventMoreThanThree())"~That's a bunch of useless junk. Trade it in somewhere else.~";
                      "~You know if you were showing me some cash I'd be a lot more interested.~";
                  }
                  if (InventMoreThanThree()) "You hold off. Your hands are full, and you don't need to drop anything.";
                  if (second == gasStationMark) "~What do you have there? Nothing. Great. Move on.~";
                  if (second == theTavernNick) {
                      if (vacuumTubeAmp in SelfPlayer) "You better not. He'd see the vacuum tube.";
                      "~What do you got there?~ the bartender asks, scratching his head.";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      if (beefJerky in SelfPlayer) "You better not. She'd see the beef jerky.";
                      if (convenienceStoreAmy.lookUp) {
                          convenienceStoreAmy.lookUp = false;
                          "~You got anything good?~ the clerk asks, returning to her comic book.";
                      }
                      "~You got anything good?~ the clerk asks, not even looking up.";
                  }
                  if (second == madameSorrasMadameSorra) return MadameSorraReading();
                  if (second == oldMadameSorra) return OldSorraReading();
                  if (second has female) "She doesn't seem to care.";
                  "He doesn't seem to care.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  if (basementWalls.tryToClean) "The faint smell of cooked meat comes off your hands.";
              Take, Pull, Push, PushDir:
                  "They're a part of you.";
              Pet, Touch:
                  "They feel a little rough to the touch.";
              Eat:
                  "Really?";
              Drop, PutOn:
                  if (second == clothes) {
                      if (InventEmpty()) "You pat down your clothes.";
                      "Your hands are full.";
                  }
                  "They're a part of you. You can't do that.";
              Insert:
                  if (second == clothes) {
                      if (InventEmpty()) "You put your hands in your pockets for a minute, but it's not that cold.";
                      "Your hands are full.";
                  }
                  "You can't do that.";
              Wave:
                  <<WaveHandsRoom location>>;
          ],
          handsStink false,
    has   concealed static pluralname proper;

  [ InventEmpty iTest;
        iTest = 0;

        if (babushka in SelfPlayer) iTest++;
        if (beefJerky in SelfPlayer) iTest++;
        if (chocolateBar in SelfPlayer) iTest++;
        if (crystalBall in SelfPlayer) iTest++;
        if (crystalCat in SelfPlayer) iTest++;
        if (crystalShard in SelfPlayer) iTest++;
        if (flask in SelfPlayer) iTest++;
        if (shedKey in SelfPlayer) iTest++;
        if (socketWrench in SelfPlayer) iTest++;
        if (sparkPlugCar in SelfPlayer) iTest++;
        if (sparkPlugMower in SelfPlayer) iTest++;
        if (vacuumTubeAmp in SelfPlayer) iTest++;
        if (vacuumTubeTV in SelfPlayer) iTest++;
        if (notes in SelfPlayer) iTest++;
        if (plate in SelfPlayer) iTest++;
        if (dollarBill in SelfPlayer) iTest++;
        if (incense in SelfPlayer) iTest++;
        if (conanComic in SelfPlayer) iTest++;

        if (iTest == 0) rtrue;
        rfalse;
  ];

  [ InventMoreThanThree iTest;
        iTest = 0;

        if (babushka in SelfPlayer) iTest++;
        if (beefJerky in SelfPlayer) iTest++;
        if (chocolateBar in SelfPlayer) iTest++;
        if (crystalBall in SelfPlayer) iTest++;
        if (crystalCat in SelfPlayer) iTest++;
        if (crystalShard in SelfPlayer) iTest++;
        if (flask in SelfPlayer) iTest++;
        if (shedKey in SelfPlayer) iTest++;
        if (socketWrench in SelfPlayer) iTest++;
        if (sparkPlugCar in SelfPlayer) iTest++;
        if (sparkPlugMower in SelfPlayer) iTest++;
        if (vacuumTubeAmp in SelfPlayer) iTest++;
        if (vacuumTubeTV in SelfPlayer) iTest++;
        if (notes in SelfPlayer) iTest++;
        if (plate in SelfPlayer) iTest++;
        if (dollarBill in SelfPlayer) iTest++;
        if (incense in SelfPlayer) iTest++;
        if (conanComic in SelfPlayer) iTest++;

        if (iTest >= 4) rtrue;
        rfalse;
  ];
