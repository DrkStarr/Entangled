
! ---------------------------------------------------------------------------- !
!       CRYSTAL CAT. 01/04/19
!
  Movabl  crystalCat "crystal cat"
    with  name 'crystal' 'cat' 'clear' 'quartz' 'statue',
          after [;
              Drop:
                  remove self;
                  score = score + 5;
                  SelfPlayer.droppedCrystalCat = true;
                  SelfPlayer.droppedCrystalBall = true;
                  move crystalShard to Player;
                  if (player in artGallery) {
                      artGallerySarah.seenCatBroken = true;
                      "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                      ^^~What? You come in here to make a trade only to break the work of art in
                      front of me? What the hell. I guess I was wrong about you. Just leave.
                      You're a mess.~
                      ^^You pick up the shard.";
                  }
                  if (player in alleyRental) {
                      "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                      ^^~Wow. Are you angry? I mean, that's no way to vent.~
                      ^^You pick up the shard.";
                  }
                  if (player in alleyBar) {
                      "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                      ^^~That's right. We don't need those new agers. Hippies and their crystals can go.~
                      ^^You pick up the shard.";
                  }
                  if (player in outsideComplex) {
                      "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                      ^^~Oh. You think you're tough? Go a few rounds with me and I'll show you.~
                      ^^You pick up the shard.";
                  }
                  if (player in gasStation) {
                      if (gasStationJerry in gasStation)
                          "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~Okay. You strung up tonight or what? Calm down. Life isn't that drastic.~
                          ^^You pick up the shard.";
                  }
                  if (player in theTavern) {
                      if (theTavernHarry in theTavern)
                          "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~Hmm. What are you trying to prove? You don't scare me,~ the old man grumbles.
                          ^^You pick up the shard.";
                      if (theTavernNick in theTavern)
                          "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~You're a little harsh. And that shard isn't going to be worth more than the cat.~
                          ^^You pick up the shard.";
                  }
                  if (player in convenienceStore) {
                      if (convenienceStoreKid in convenienceStore)
                          "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~Wow. You're nuts. I've never seen somebody do that,~ the kid says in shock.
                          ^^You pick up the shard.";
                      if (convenienceStoreAmy in convenienceStore)
                          "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~Farout, that's really intense. Be careful, who knows what you unleased.~
                          ^^You pick up the shard.";
                  }
                  "The crystal cat shatters, hitting the ground, leaving behind a quartz shard.
                  ^^You pick up the shard.";
              Insert:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "Since it's clear quartz, it might work, but it's too big to fit in there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == basementTubes || second == brokenTube) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that.";
          ],
          before [;
              Attack:
                  <<Drop self>>;
              Buy:
                  if (self in player) "You already have that.";
              Insert:
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Examine, Search:
                  "At a foot tall, it's a big statue. But the crystal cat is too perfect and had to be molded.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "The crystal doesn't give off a scent.";
              PutOn:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "Since it's clear quartz it might work, but it's too big to fit in there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that.";
              Give:
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~Oh. That's nice. Thanks, but I don't need it.~";
                  }
                  if (second == theTavernNick) "~What? That thing? You can keep it.~";
                  if (second == alleyBarPhil) {
                      print "~Nice statue. I guess you got it from Sarah. Better be careful with it";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) "~Look. I'm not doing my next project on crystals. I did that three years ago and lost.~";
                  if (second == alleyRentalNancy) "~Like. What are you going to do with that? It's a little big and probably too delicate.~";
                  if (second == gasStationJerry) "He looks at it for a minute. ~That's different, but I don't need it. Maybe you should keep it.~";
                  if (second == theTavernHarry) "~Why would I want that? I got my drink. I'm fine.~";
                  if (second == smallParkEddie) "~I've heard Sarah talk about that, but I don't need it. Do you have anything else?~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == artGallerySarah) "~We made a fair trade. So keep it. I need to get hold of my sculptor.~";
                  if (second == madameSorrasMadameSorra) "~I see dark energy around that. Whoever gave it to you must be evil.~";
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Show:
                  if (second == alleyBarPhil) {
                      print "~That's a nice piece. I can't say I'm really into fine art, but hopefully you'll enjoy it";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) "The kid snorts to himself, turning his back as he complains to the clerk.";
                  if (second == alleyRentalNancy) "~It's nice and all. But, like. What good is it?~";
                  if (second == gasStationJerry) "~Nice cat. What do you want me to say?~";
                  if (second == theTavernNick) {
                      if (self.showNick) "~Maybe I didn't make myself clear. I don't want it.~";
                      self.showNick = true;
                      "~I've seen that piece around. You got it from the gallery. Nobody has bought that statue in ages.
                      I bet you made Sarah's day.~";
                  }
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == smallParkEddie) "~Did you get that from Sarah? It looks like something I've heard her talk about.~";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~Never seen anything like that before. Wow, it's pretty neat.~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == madameSorrasMadameSorra) "~Do not show me such an evil thing. Whoever gave it to you is wicked indeed.~";
                  if (second == artGallerySarah) "~We made a fair trade, don't you think? Now I can pay off that consignment.~";
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              Take, Remove:
                  "You already have that.";
              Turn, PushDir, Push, Pull:
                  "You don't need to do that.";
              Pet, Touch:
                  "The crystal is smooth to the touch.";
              Rub:
                  "The crystal is clean. The only handprints are yours.";
              ThrowAt:
                  if (self in player) {
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      if (second == artGallerySarah) {
                          remove self;
                          score = score + 5;
                          SelfPlayer.droppedCrystalCat = true;
                          SelfPlayer.droppedCrystalBall = true;
                          move crystalShard to Player;
                          artGallerySarah.seenCatBroken = true;
                          "You throw the crystal cat at the curator. She dodges as it shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~What? Are you crazy? I should call the cops. But you did me a favor.
                          Get out of here before I have to.~
                          ^^You pick up the shard.";
                      }
                      <<Drop self>>;
                  }
              Eat:
                  "The statue is too larger for you to put into your mouth. You couldn't even try.";
              Taste:
                  "As clean as it is, how could it taste any good?";
              Replace:
                  if (player in basement) {
                      "Since it's clear quartz, it might work, but it's too big to fit in there.";
                  }
                  rfalse;
          ],
          showNick false,
    has   concealed;
