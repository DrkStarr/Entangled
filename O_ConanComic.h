
! ---------------------------------------------------------------------------- !
!       CONAN COMIC. 01/10/19
!
  Movabl  conanComic "Conan comic"
    with  name 'conan' 'comic' '115' 'ink' 'anniversary' 'edition',
          after [;
              Drop, Insert:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == basementTubes || second == brokenTube) "It doesn't belong there.";
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
                  if (self in clothes) "It's already in your pocket.";
                  if (second == clothes) {
                      move self to clothes;
                      print "You stick the comic in your back pocket";
                      if (self.wrinkled) ".";
                      self.wrinkled = true;
                      ", wrinkling it a bit.";
                  }
              Examine, Search:
                  if (self in clothes) {
                      move self to player;
                      print "(first taking the comic from your pocket)^";
                  }
                  print "It's Conan The Barbarian #115, the 10th-anniversary edition. Conan attacks in the center of the
                  cover, drawn on top of a yellow background that has green reliefs of Conan attacking different
                  enemies over the years";
                  if (self.wrinkled) ". The comic is also a bit wrinkled from being in your back pocket.";
                  ".";
              Rub, Touch:
                  if (self.wrinkled) "You're not going to straighten out the wrinkles.";
                  "There's no need. You'd just get ink on your hands.";
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
              Read, Open:
                  if (self in clothes) {
                      move self to player;
                      print "(first taking the comic from your pocket)^";
                  }
                  "You have no time to look through the comic. Maybe somebody else would like it.";
              Give:
                  if (second == smallParkEddie) {
                      if (smallParkEddie.askHaveAny) smallParkEddie.dontKillAskHaveAny = true;
                      smallParkEddie.askHaveAny = true;
                      "~Interesting comic, but do you have anything useful? Food? Drink, maybe?~";
                  }
                  if (second == gasStationJerry) {
                      remove self;
                      score = score + 5;
                      self.giveToJerry = true;
                      gasStationTV.&name-->6 = 'ph02626';
                      move gasStationComic to gasStation;
                      "~Thanks,~ he says, taking it from you as he opens the booth for a minute.
                      He shuts off the television, mumbling something to himself. Then he turns to the comic.
                      ~Thanks again,~ he says, riffling through the pages.";
                  }
                  if (second == theTavernHarry) "~Come on, what is this? You think I'm a kid?~";
                  if (second == convenienceStoreAmy) {
                      if (self.giveToAmy) "~I already have the comic I want. You keep it.~";
                      self.giveToAmy = true;
                      "~You know, Conan's not my thing. Wonder Woman is the real hero.~";
                  }
                  if (second == theTavernNick) "~What? Are you trying to trade, 'cause I'm not giving you anything for a dime store comic.~";
                  if (second == alleyBarPhil) {
                      print "~I'm too old for comics now. But Buck Rogers was my favorite";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~Oh, you know, I'm not a nerd like you.~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~Vhy do you bother me with such a thing?~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~I'm not a child, and I don't care to read that.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Pull, PushDir, Push:
                  "You don't need to do that.";
              Pet:
                  "You feel nothing unexpected.";
              Show:
                  if (second == smallParkEddie) "~Nice comic, but what about it?~";
                  if (second == alleyBarPhil) {
                      print "~I used to read comics a long time ago. Back in the papers. Not books like that";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~Comics are for nerds. I'm not into that.~";
                  if (second == gasStationJerry) "~Conan. Sweet comic. Some nice drawings in there,~ he says blushing.";
                  if (second == theTavernNick) "~Yeah, yeah. One second,~ he says not even looking at it.";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == madameSorrasMadameSorra) "~Vhy do you bother me with such a thing?~";
                  if (second == convenienceStoreAmy) "~Yeah. I see it. I sold it to you.~";
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Please don't waste my time. I'm kind of busy here.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              SmellNoun:
                  if (self in clothes) {
                      move self to player;
                      print "(first taking the comic from your pocket)^";
                  }
                  if (SmellTest()) rtrue;
                  "It smells of freshly printed ink.";
              Take:
                  if (self in clothes) {
                      move self to player;
                      "You take the comic from your pocket.";
                  }
              Remove:
                  <<Take self>>;
              ThrowAt:
                  if (self in player) {
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "It lacks the mass to do any damage.";
                  }
              Eat, Taste:
                  "Who do you think you are? Grunk? You're not going to chew through all that paper.";
          ],
          wrinkled false,
          giveToAmy false,
          giveToJerry false;
