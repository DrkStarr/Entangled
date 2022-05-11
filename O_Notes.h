
! ---------------------------------------------------------------------------- !
!       NOTES. 01/05/19
!
  Movabl  notes "notes"
    with  name 'note' 'notes' 'paper' 'papers' 'drawings' 'entries' 'bunch',
          after [;
              Drop, Insert:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "They don't belong there.";
                  if (second == shedLawnMower) "They don't belong there.";
                  if (second == basementTubes || second == brokenTube) "They don't belong there.";
                  if (second == basementGenerator) "They don't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "They don't belong there.";
                  }
                  "You don't want to lose those. You might need them.";
          ],
          before [;
              Buy:
                  if (self in player) "You already have that.";
              Consult:
                  "The notes aren't structured that way. Looking them over, you see they're not structured at all. It's like a kid put these together.";
              Insert:
                  if (self in clothes) "They're in your pocket.";
                  if (second == clothes) {
                      move self to clothes;
                      "You stick the notes in your back pocket.";
                  }
              Examine, Search:
                  if (self in player) {
                      return LookAtNotes();
                  } else {
                      move self to player;
                      print "(first taking the notes)^";
                      return LookAtNotes();
                  }
              Rub:
                  if (currentTime()) "The notes are yellowed. You're not going to be able to clean them.";
                  "The notes look pretty clean. You don't need to mess with them.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "They don't smell. They're just a bunch of papers.";
              Touch:
                  "The paper's thick, making the notes bulky.";
              PutOn:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "They don't belong there.";
                  if (second == shedLawnMower) "They don't belong there.";
                  if (second == basementGenerator) "They don't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "They don't belong there.";
                  }
                  "You don't want to lose those. You might need them.";
              Read:
                  if (self in clothes) {
                      move self to player;
                      print "(first taking the notes)^";
                  }
                  if (self in player) {
                      if (ReadNotes(0)) rtrue;
                  } else {
                      move self to player;
                      print "(first picking up the notes)^";
                      if (ReadNotes(0)) rtrue;
                  }
              Give:
                  if (self in player) {
                  } else {
                      move self to player;
                      print "(first taking the notes)^";
                  }
                  if (second == gasStationMark) {
                      if (gasStationMark.eyesOpen) {
                          gasStationMark.eyesOpen = false;
                          "~Naw. I don't want those,~ the attendant says, turning back to his phone.";
                      }
                      if (gasStationMark.seenScientist)
                          "~Naw. I don't want those. Catch that guy or something,~ the attendant says, not even looking up.";
                      "~I don't want those,~ the attendant says, not even looking up.";
                  }
                  if (second == gasStationScientist) {
                      if (iScientist == 3) "You're too far away to give him that.";
                      "You can't see him anymore.";
                  }
                  if (second == smallParkEddie) "~Some interesting pictures you got there, but I'm not that smart.~";
                  if (second == gasStationJerry) "~I already have enough homework. You can keep it.~";
                  if (second == theTavernHarry) "~Even though I look it, I'm not a rocket scientist.~";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      if (self.giveToAmy) "~Like I said. I don't have a clue about that.~";
                      self.giveToAmy = true;
                      "~I'm smart and all, but I don't know what that's all about.~";
                  }
                  if (second == theTavernNick) "~I'm not into the whole technical thing. I hate to read manuals.~";
                  if (second == alleyBarPhil) {
                      if (basement.firstTime)
                          "~Sorry. I'm a little busy right now,~ he says, fishing out another glass from the bin.";
                      if (self.giveToPhil) {
                          print "~You can keep that. It's a joke";
                          return PhilWash();
                      }
                      self.giveToPhil = true;
                      "The bartender scans it, ~That's a joke. Good luck trying to build something like that.~";
                  }
                  if (second == alleyRentalNancy) "~Like. Why would you even try to give me that?~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~I can see many mysteries surrounding that. Much is in flux.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Look. I have a business to run. I have plenty of my own paperwork.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == mapleRoadTom) {
                      if (self.showToTom) "~That's not important. There's a mothership out there.~";
                      self.showToTom = true;
                      "~That might be important,~ he says, ~but when the mothership touches down you're not going to care about it at all.~";
                  }
                  if (second == convenienceStoreOldAmy) {
                      if (convenienceStoreOldAmy.lookUp) convenienceStoreOldAmy.dontKillLookUp = true;
                      convenienceStoreOldAmy.lookUp = true;
                      "~Can't you see I'm doing something here,~ she says with a bit of disgust in her voice.";
                  }
                  if (second == tattooShopNick) {
                      "~I don't need that,~ he says only glancing at it, ~I'm an artist not an engineer.~";
                  }
                  if (second == oldMadameSorra) {
                      if (self.giveOldSorra) "~No. I can not help you. You must walk your own path.~";
                      self.giveOldSorra = true;
                      "~Much is vrong with that. Yes. I see it at the center of the night. Be careful who you give it to.~";
                  }
                  if (second == convenienceStoreKid) return GiveToKid();
                  if (second == bowlingAlleyKids) return KidHit();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Pull, PushDir, Push:
                  "You don't need to do that.";
              Pet:
                  "You feel nothing unexpected.";
              Show:
                  if (self in player) {
                  } else {
                      move self to player;
                      print "(first taking the notes)^";
                  }
                  if (second == gasStationMark) {
                      if (gasStationMark.eyesOpen) {
                          gasStationMark.eyesOpen = false;
                          "~I don't want those,~ the attendant says, turning back to his phone.";
                      }
                      if (gasStationMark.seenScientist)
                          "~You keep 'em. Maybe you can even catch that guy,~ the attendant says, not even looking up.";
                      "~What would I do with those,~ the attendant says, not even looking up.";
                  }
                  if (second == gasStationScientist) {
                      if (iScientist == 3) "You're too far away to show him that.";
                      "You can't see him anymore.";
                  }
                  if (second == smallParkEddie) "~I like the different diagrams, but what's it all about?~";
                  if (second == alleyBarPhil) {
                      if (basement.firstTime)
                          "~Sorry. I'm a little busy right now,~ he says, fishing out another glass from the bin.";
                      if (self.giveToPhil) {
                          print "~You can keep that. It's a joke";
                          return PhilWash();
                      }
                      self.giveToPhil = true;
                      "The bartender scans it, ~That's a joke. Good luck trying to build something like that.~";
                  }
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
                  if (second == alleyRentalNancy) "~Is that supposed to impress me?~ she asks, not even looking up.";
                  if (second == gasStationJerry) "~Figure it out on your own. I have plenty of homework to do.~";
                  if (second == theTavernNick) "~What do you got there,~ he says, not even looking at it.";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == madameSorrasMadameSorra) {
                      if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                      madameSorrasMadameSorra.spiritsRestless = true;
                      "~I can see many mysteries surrounding that. You make the spirits restless.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      if (self.giveToAmy) "~Like I said. I don't have a clue about that.~";
                      self.giveToAmy = true;
                      "~I'm smart and all, but I don't know what that's all about.~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~I'm kind of busy right now,~ she says without looking up.";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == mapleRoadTom) {
                      if (self.showToTom) "~That's not important. There's a mothership out there.~";
                      self.showToTom = true;
                      "~That might be important,~ he says, ~but when the mothership touches down you're not going to care about it at all.~";
                  }
                  if (second == convenienceStoreOldAmy) {
                      if (convenienceStoreOldAmy.lookUp) convenienceStoreOldAmy.dontKillLookUp = true;
                      convenienceStoreOldAmy.lookUp = true;
                      "~Can't you see I'm doing something here,~ she says with a bit of disgust in her voice.";
                  }
                  if (second == tattooShopNick) {
                      "~That's not half as interesting as some of these tattoos in this magazine,~ he says without looking at it.";
                  }
                  if (second == oldMadameSorra) "The old woman pays you no mind as she stares into the crystal ball.";
                  if (second == convenienceStoreKid) return GiveToKid();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
              Take:
                  if (self in clothes) {
                      move self to player;
                      "You take the notes from your pocket.";
                  }
              ThrowAt:
                  if (self in player) {
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "They lack the mass to do any damage.";
                  }
              Remove:
                  <<Take self>>;
              Eat, Taste:
                  "You don't want to chew them up. They might come in handy.";
          ],
          giveToPhil false,
          giveToAmy false,
          notesScored false,
          giveNotesScored false,
          showToTom false,
          lookFirstTime true,
          giveOldSorra false,
   has    pluralname;

  [ ReadNotes vpass;
        if (basement.firstTime) {
            print "You don't have time to read right now. ";
            if (mapleRoadTom.helpTom) "You need to help Tom. It looks like a bunch of useless scientific writing anyways.";
            if (bowlingAlley.firstTime) "You need to find Sam. It looks like a bunch of useless scientific writing anyways.";
            "You need to find out what is going on. It looks like a bunch of useless scientific writing anyways.";
        }
        if (notes.notesScored == false) {
            notes.notesScored = true;
            score = score + 5;
        }
        notes.lookFirstTime = false;
        if (vpass == 0) print "Looking the notes over,";
        else print "Looking them over further,";
        " you realize they're for a time machine designed to go
        40 years into the past. According to this, the scientist wanted to explore the
        end of an era, right before computers took off - 1980 by the looks of it.
        Reading further, the one helpful thing you pull out of it all is about an
        automatic return feature. When the machine is activated, pressing the button on the panel
        will do it. The rest of it explains how to avoid anomalies in the timeline.^
        ^Crossed out at the end of it all, it says that entanglement can affect the
        instruments, possibly creating a quantum explosion. The odds are
        low, but the two bodies caught up in the new timeline will generate
        a blast that will probably kill both.";
  ];

  [ GiveToKid;
        convenienceStore.walkIn = false;
        give convenienceStoreAmy ~scenery;
        notes.giveNotesScored = true;
        StopDaemon(convenienceStore);
        remove convenienceStoreKid;
        move convenienceStoreMelGone to convenienceStore;
        remove notes;
        score = score + 5;
        "You tap the kid on the shoulder, showing him the notes.^
        ^~What's this,~ he says cynically. Yanking it out of your hand,
        he takes a minute to look the notes over. Then his face lights up.^
        ^~Wow, I've never seen anything like this before. This is better than I could
        hope. Forget the comic. Thanks.~^
        ^The clerk addresses you as the kid walks out the door. ~Wow, that was
        starting to drive me crazy.~ Taking a second, she wipes off a bit of sweat
        and then returns to her comic book.";
  ];

  [ LookAtNotes;
        if (basement.firstTime) {
            if (iTime == PAST) "The notes look new, with pages that are white but wrinkled. The stack of papers has a few hand drawings with entries to explain it.";
            "The notes are old. Yellowed by time. The stack of papers has a few hand drawings with entries to explain it.";
        }
        print "The notes look new, with pages that are white but wrinkled.";
        if (notes.lookFirstTime) {
            notes.lookFirstTime = false;
            print "^^";
            if (ReadNotes(1)) rtrue;
        }
        " The stack of papers has a few hand drawings with entries to explain it.";
  ];
