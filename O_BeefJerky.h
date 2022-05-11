
! ---------------------------------------------------------------------------- !
!       BEEF JERKY. 09/30/17
!
  Movabl  beefJerky "beef pack"
    with  name 'sealed' 'beef' 'jerky' 'stick' 'plastic' 'meat' 'pack' 'package' 'wrapper' 'pac' 'vacuum' 'sealed' 'oberto' 'food',
          describe [;
              if (self in rustyGate) rtrue;
          ],
          after [;
              Drop, Insert:
                  if (second == rustyGateRustyGate) return GiveBeefToDog(1);
                  if (player in rustyGate) return GiveBeefToDog(2);
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
                  if (self in rustyGate) "That's on the other side of the gate.";
                  "You already have that.";
              Insert:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Examine, Search:
                  if (self in rustyGate) "The dog munches on the sealed beef, trying to get through the plastic.";
                  "The beef's contained in a vacuum-sealed pack and stamped with a label that reads, Oberto.";
              Rub, Touch:
                  "The pack is sealed. That does nothing.";
              PutOn:
                  if (second == rustyGateRustyGate) return GiveBeefToDog(1);
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
                  if (self in rustyGate) "That's on the other side of the gate.";
                  if (second == rustyGateDog) return GiveBeefToDog(2);
                  if (second == smallParkEddie) {
                      "~Thanks, but no thanks,~ the bum says, shaking his head. ~Jerky doesn't sit well with me. Too hard on my stomach.~";
                  }
                  if (second == convenienceStoreAmy) "That could cause all sorts of problems. You better keep it to yourself.";
                  if (second == madameSorrasMadameSorra) {
                      "~You have stolen this, haven't you? I see it in your eyes.~";
                  }
                  if (second == theTavernNick) "~No thanks, plus if I wanted something, we have a kitchen in the back.~";
                  if (second == alleyBarPhil) {
                      print "~You know we have a kitchen here if you actually wanted something";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~I'm not that hungry.~";
                  if (second == gasStationJerry) "~No thanks, I got plenty of snacks inside.~";
                  if (second == theTavernHarry) "~What am I going to do with that?~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~I ate too much of that stuff when I lived on the commune. We had our own smoker. I've had enough.~";
                  }
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Show:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  if (second == rustyGateDog) "The dog's ears perk up a bit for a second, but then he growls and starts to bark again.";
                  if (second == smallParkEddie) {
                      "You show the middle-aged man the beef pack.
                      ^^~Oh, man, no thanks. That would tear up my stomach.~";
                  }
                  if (second == convenienceStoreAmy) "That could cause all sorts of problems. You better keep it to yourself.";
                  if (second == theTavernNick) {
                      if (self.showedNick) "~I didn't think it was funny the first time.~";
                      self.showedNick = true;
                      "~Is that some kind of joke. Showing me your beef?~";
                  }
                  if (second == alleyBarPhil) {
                      print "~Yeah. We got a kitchen here. Really don't need to bring your own";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~Very funny,~ she says with a smile, ~I get it. Showing me your beef. You think you're clever.~";
                  if (second == gasStationJerry) "~So what? I got my own if I want it.~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == madameSorrasMadameSorra) {
                  if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                      madameSorrasMadameSorra.spiritsRestless = true;
                      "~A thief you are. You make the spirits restless.~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Why are you showing off your beef?~";
                  }
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              Pull, Remove, Take:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  "You already have that.";
              PushDir, Push, Turn:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  "You don't need to do that.";
              Open:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  "There's no reason to open it. You're not that hungry.";
              Close:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  "It's already sealed shut.";
              Eat, Taste:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  "It would be tasty, Oberto makes great jerky. But it was hard to come by. You shouldn't waste it.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "It's sealed. You can't smell through the plastic.";
              ThrowAt:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  if (second == rustyGateDog) return GiveBeefToDog(2);
                  move self to player;
                  if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                  "You better hold on to that.";
              Wave:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  if (SelfPlayer in convenienceStore) "That could cause all sorts of problems. You better keep it to yourself.";
              Pet:
                  if (self in rustyGate) "That's on the other side of the gate.";
                  "The plastic feels rough. The meat is vacuum-sealed.";
              default:
                  if (self in rustyGate) "That's on the other side of the gate.";
          ],
          showedNick false,
          giveToSorra false;

  [ GiveBeefToDog vpass;
        rustyGateDog.eatingJerky = true;
        rustyGate.dogBarking = false;
        move beefJerky to rustyGate;
        switch (vpass) {
            1: print "You put the pack of beef on the edge of the fence. The dog jumps at it.";
            2: print "You toss the pack of beef jerky in front of the dog.";
        }
        " Before it hits the ground, the dog bites only to find plastic. Tearing at it, he fights against the protective coating, trying to get it open.";
  ];
