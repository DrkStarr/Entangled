
! ---------------------------------------------------------------------------- !
!       WATCH. 08/09/16
!
  Movabl  watch "watch"
    with  name 'wrist' 'watch' 'time' 'alarm' 'cheap' 'digital' 'casio' 'digits' 'wristband' 'ribs',
          short_name "your watch",
          after [;
              Drop, Insert:
                  move self to player;
                  "You don't want to lose that. How else are you going to keep time?";
          ],
          before [;
              Buy:
                  if (self in player) "You already have that.";
              Insert:
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              PutOn:
                  move self to player;
                  "You don't want to lose that. How else are you going to keep time?";
              Disrobe, Remove:
                  "You don't want to lose that. How else are you going to keep time?";
              Rub:
                  "The face of your watch is clean. The digits easy to read.";
              Touch:
                  "Rough to the touch, the wristband is plastic and ribbed.";
              Examine, Search:
                  iDisplayMinute = iMinute;
                  iDisplayMinute++;
                  iDisplayHour = iHour;
                  if (iDisplayMinute == 60) {
                      iDisplayHour++;
                      if (iDisplayHour==13) iDisplayHour=1;
                      iDisplayMinute = 0;
                  }
                  print "It's an old digital Casio. ";
                  if (iAMPM == 0) {
                      if (iMinute > 8) {
                          if (iDisplayMinute == 0) {
                              print "Looking at it you see it's October 2020, at ", iDisplayHour, ":0", iDisplayMinute, " pm.
                              The date's missing, but it's a cheap watch.^";
                              rtrue;
                          }
                          print "Looking at it you see it's October 2020, at ", iDisplayHour, ":", iDisplayMinute, " am.
                          The date's missing, but it's a cheap watch.^";
                          rtrue;
                      } else {
                          print "Looking at it you see it's October 2020, at ", iDisplayHour, ":0", iDisplayMinute, " am.
                          The date's missing, but it's a cheap watch.^";
                          rtrue;
                      }
                  }
                  if (iMinute > 8) {
                      if (iDisplayMinute == 0) {
                          if (iDisplayHour == 12) {
                              if (iAMPM == 1) print "Looking at it you see it's October 2020, at ", iDisplayHour, ":0", iDisplayMinute, " am. The date's missing, but it's a cheap watch.^";
                              if (iAMPM == 0) print "Looking at it you see it's October 2020, at ", iDisplayHour, ":0", iDisplayMinute, " pm. The date's missing, but it's a cheap watch.^";
                          } else {
                              print "Looking at it you see it's October 2020, at ", iDisplayHour, ":0", iDisplayMinute, " pm. The date's missing, but it's a cheap watch.^";
                          }
                          rtrue;
                      }
                      print "Looking at it you see it's October 2020, at ", iDisplayHour, ":", iDisplayMinute, " pm. The date's missing, but it's a cheap watch.^";
                      rtrue;
                  }
                  print "Looking at it you see it's October 2020, at ", iDisplayHour, ":0", iDisplayMinute, " pm. The date's missing, but it's a cheap watch.^";
                  rtrue;
              Give:
                  if (second == gasStationMark) {
                      if (self.giveToMark) {
                          self.giveToMark = false;
                          "~What? You want to trade me your watch? You must be desperate.~";
                      }
                      "~I said no. Move along.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~We don't take trade-ins here. It'll have to be cash. Sorry.~";
                  }
                  if (second == theTavernNick)
                      "~I'd be willing to trade you something for a bottle. I know how it is.
                      But I'm not going to take this cheap watch.~";
                  if (second == alleyBarPhil) {
                      if (basement.firstTime)
                          "~Sorry. I'm a little busy right now,~ he says, fishing out another glass from the bin.";
                      print "~You really want to trade that for some booze? I can't do that. You'll have to go somewhere else";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) {
                      convenienceStore.turningToClerk = true;
                      "~A science project about time. Interesting. How would I go about that?~";
                  }
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
                  if (second == alleyBarCustomers || second == bowlingAlleyCustomers) "They seem content to themselves, and they've always been cliquish.";
                  if (second == alleyRentalNancy) "~What am I going to do with that? You keep it.~";
                  if (second == gasStationJerry) "~I'm not sure what you want. Just get out of here. I don't want to deal with it.~";
                  if (second == theTavernHarry) "~I don't want your junk nor your company, why don't you get out of here?~";
                  if (second == smallParkEddie) "~Thanks anyway, but I don't need it. Time be time.~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~Vhat use do I have for such a thing?~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      print "~Don't make me laugh";
                      if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) ". It's been a long day.~";
                      ".~";
                  }
                  if (second == oldMadameSorra) "~I do not vant your worldly possessions.~";
                  if (second == convenienceStoreOldAmy) "~You know. Deja Vu. But, we don't take trade-ins here.~";
                  if (second == mapleRoadTom) "~That's not going to help with the aliens. Find something to signal them with.~";
                  if (second == tattooShopNick) "~I know you're not trying to trade that. The work I do is worth a lot more than that cheap watch.~";
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == player) rfalse;
              Take:
                  "You already have that.";
              Pet:
                  "You feel nothing unexpected.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "It smells a bit ripe, but you don't take off your watch.";
              Show:
                  if (second == gasStationMark) "~Looks like the date's broken. Could you find anything cheaper?~";
                  if (second == alleyBarPhil) {
                      if (basement.firstTime)
                          "~Sorry. I'm a little busy right now,~ he says, fishing out another glass from the bin.";
                      if (self.showWatchToPhil) "~I don't get the joke.~";
                      self.showWatchToPhil = true;
                      "He looks at it for a minute. ~What? Is that some sort of joke? The year's wrong and the date is broken.~";
                  }
                  if (second == alleyRentalNancy) "She doesn't even look at it. ~Like. I hope you're not trying to win me over, 'cause that's a cheap piece of junk.~";
                  if (second == gasStationJerry) {
                      if (gasStationJerry.eyesOpen) {
                          gasStationJerry.eyesOpen = false;
                          if (conanComic.giveToJerry) "Not even looking at the watch, he turns back to the comic. ~I got my own. Don't need another.~";
                          "Not even looking at the watch, he turns back to the television. ~I got my own. Don't need another.~";
                      }
                      if (conanComic.giveToJerry) "He doesn't look up from the comic. ~I got my own. Don't need another.~";
                      "He doesn't look up from the television. ~I got my own. Don't need another.~";
                  }
                  if (second == theTavernNick) {
                      if (self.showWatchToNick) "~That thing is broken. You can't see the date plus the year's off by a mile.~";
                      self.showWatchToNick = true;
                      "~I don't even wear a watch,~ he says, looking it over, ~and the year is way off on that thing.~";
                  }
                  if (second == theTavernHarry) "Without looking at it, he says. ~You know what you can do with that, don't you?~";
                  if (second == smallParkEddie) {
                      if (self.showWatchToEddie) "~Yeah, that thing's broken. It's not even worth holding on to.~";
                      self.showWatchToEddie = true;
                      "~Digital. Hm? Nice. Wait. What's wrong with the year?~";
                  }
                  if (second == madameSorrasMadameSorra) "Looking into your eyes, she says, ~and what does that mean to you?~";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      if (self.showWatchToAmy) "~That just seems odd to me.~";
                      self.showWatchToAmy = true;
                      convenienceStoreAmy.askAboutWatch = true;
                      "~Nice. One of those new digital things. Wait? Does that say 2020?~";                                    ! Yes - ~Why would you do that?~
                  }                                                                                                            ! No - ~Well I know I'm not blind.~
                  if (second == convenienceStoreKid) "You can see the kid stew on it for a minute before turning back to the clerk.";
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                      if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      if (self.showWatchToSarah) "~Like I said. I'm not impressed by material things.~";
                      self.showWatchToSarah = true;
                      "~I'm not impressed by material things. You should seek out your higher self.~";
                  }
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
                  if (second == oldMadameSorra) "~I can see even though I am old. Vut do you vant with that?~";
                  if (second == convenienceStoreOldAmy) "~Digital. Wow. Talk about old school.~";
                  if (second == mapleRoadTom) "~Nice watch and all, but how is that going to help with the aliens?~";
                  if (second == tattooShopNick) {
                      if (tattooShopNick.lookingUp)
                          "~What about it?~ he asks, waiting on you.";
                      tattooShopNick.lookingUp = true;
                      "~What about it?~ he asks, looking up from the magazine.";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
              SwitchOn:
                  if (self.turnedOn) "The hourly alarm is already on.";
                  self.turnedOn = true;
                  "Pressing the alarm twice, you turn it on.";
              SwitchOff:
                  if (self.turnedOn) {
                      self.turnedOn = false;
                      "Pressing the alarm twice, you turn it off.";
                  }
                  "The alarm has already been turned off.";
              ThrowAt:
                  if (self in player) "You might need that, better hold onto it.";
              Eat:
                  return PlayerEatWatch();
              Push:
                  if (self.turnedOn) <<SwitchOff self>>;
                  <<SwitchOn self>>;
          ],
          turnedOn true,
          giveToMark true,
          triedToEat false,
          showWatchToNick false,
          showWatchToEddie false,
          showWatchToPhil false,
          showWatchToAmy false,
          showWatchToSarah false,
    has   worn proper clothing;

  [ PlayerEatWatch;
        if (watch.triedToEat) "Even Animal wouldn't eat that.";
        watch.triedToEat = true;
        "What are you a muppet like Animal?";
  ];
