
! ---------------------------------------------------------------------------- !
!       CRYSTAL BALL. 01/15/18
!
  Movabl  crystalBall "crystal ball"
    with  name 'crystal' 'ball' 'clear' 'quartz',
          after [;
              Drop:
                  remove self;
                  score = score + 5;
                  SelfPlayer.droppedCrystalBall = true;
                  move crystalShard to Player;
                  if (player in artGallery) {
                      artGallerySarah.seenBallBroken = true;
                      "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                      ^^~Oh my god. What are you doing?~  the curator says in astonishment, ~That
                      piece was priceless and you destroyed it. I know some people can be stupid,
                      but you take the cake!~
                      ^^You pick up the shard.";
                  }
                  if (player in alleyRental) {
                      "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                      ^^~Wow. Are you angry? I mean, that's no way to vent.~
                      ^^You pick up the shard.";
                  }
                  if (player in alleyBar) {
                      "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                      ^^~That's right. We don't need those new agers. Hippies and their crystals can go.~
                      ^^You pick up the shard.";
                  }
                  if (player in outsideComplex) {
                      "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                      ^^~Oh. You think you're tough? Go a few rounds with me and I'll show you.~
                      ^^You pick up the shard.";
                  }
                  if (player in gasStation) {
                      if (gasStationJerry in gasStation)
                          "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~Okay. You strung up tonight or what? Calm down. Life isn't that drastic.~
                          ^^You pick up the shard.";
                  }
                  if (player in theTavern) {
                      if (theTavernHarry in theTavern)
                          "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~Hmm. What are you trying to prove? You don't scare me,~ the old man grumbles.
                          ^^You pick up the shard.";
                      if (theTavernNick in theTavern)
                          "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~You're a little harsh. And that shard isn't going to be worth more than the ball.~
                          ^^You pick up the shard.";
                  }
                  if (player in convenienceStore) {
                      if (convenienceStoreKid in convenienceStore)
                          "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~Wow. You're nuts. I've never seen somebody do that,~ the kid says in shock.
                          ^^You pick up the shard.";
                      if (convenienceStoreAmy in convenienceStore)
                          "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
                          ^^~Farout, that's really intense. Be careful, who knows what you unleased.~
                          ^^You pick up the shard.";
                  }
                  "The crystal ball shatters, hitting the ground, leaving behind a quartz shard.
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
                  if (self in madameSorras) {
                      if (oldMadameSorra in madameSorras) rfalse;
                      if (madameSorrasMadameSorra in madameSorras) rfalse;
                      move self to player;
                      print "You pick up the crystal ball, dropping it where you stand.^^";
                  }
                  <<Drop self>>;
              Buy:
                  if (self in player) "You already have that.";
              Insert:
                  if (self in madameSorras) rfalse;
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Examine:
                  if (self in madameSorras) "The crystal ball is made from clear quartz and distorts the room when you look at it.";
                  "Looking at the crystal ball, you see it's made from clear quartz that distorts the world around it.";
              Search:
                  if (self in madameSorras) {
                      if (oldMadameSorra in madameSorras || madameSorrasMadameSorra in madameSorras)
                          "Looking into the ball, the room twists and Madame Sorra is upside down.
                          You try to concentrate for a minute to see if anything appears, but it doesn't.";
                  }
                  "Looking into the crystal ball, it warps everything around it.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "The crystal doesn't give off a scent.";
              PutOn:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "Since it's clear quartz, it might work, but it's too big to fit in there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that.";
              Rub:
                  "You rub it for a bit, but you'll never get all the grease off.";
              Give:
                  if (self in madameSorras) rfalse;
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~It's pretty. Thanks. But I don't need it.~";
                  }
                  if (second == theTavernNick) "~Tempting. The crystal might be worth a bottle, but I don't have any need for it.~";
                  if (second == alleyBarPhil) "~I don't want that. What do you think I am, some sort of hippie? Give it to a long hair.~";
                  if (second == convenienceStoreKid) "~Look. I'm not doing my next project on crystals. I did that three years ago and lost.~";
                  if (second == alleyRentalNancy) "~If that's the fortune tellers, I don't want it.~";
                  if (second == gasStationJerry) "~Where did you get that? It puts Mom's crystals to shame.~";
                  if (second == theTavernHarry) "~Why would I want that? I got my drink. I'm fine.~";
                  if (second == smallParkEddie) "~What would I do with that? Do you have anything else?~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == artGallerySarah) {
                      move crystalCat to Player;
                      artGallerySarah.tradedCat = true;
                      remove artGalleryStatue;
                      remove self;
                      score = score + 5;
                      "She looks at it for a minute as a slight smile creases her lips.
                      ~I wouldn't normally trade you for it, but you seem like someone that might
                      appreciate the statue, here take it,~ she says, handing you the cat as she takes
                      the crystal ball.^^Wiping it off she puts it behind the counter, out of sight.";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Show:
                  if (self in madameSorras) rfalse;
                  if (second == convenienceStoreKid) "The kid snorts to himself, turning his back as he complains to the clerk.";
                  if (second == alleyBarPhil) "~Yeah. Crystals are all the rage, flipping new agers.~";
                  if (second == alleyRentalNancy) "~Nice crystal. But it looks like the one the fortune teller uses. I bet it's cursed. She creeps me out.~";
                  if (second == gasStationJerry) "~Do you go for all that new age stuff? It seems astrology and crystals are a real hit. I gave my Mom a mood ring for Christmas.~";
                  if (second == theTavernNick) {
                      "~That's sweet. But you might want to show it to the curator over at the gallery. She's more into that sort of thing.~";
                  }
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == smallParkEddie) "~Nice crystal ball. You one of them new age people?~";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~Never seen anything like that before. Wow, it's pretty neat.~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (artGallerySarah.tellAboutSorra) "~You're lucky you got that. I swear she did it to spite me.~";
                      "~That looks like the old fortune-teller's ball,~ she says looking at the cat, ~how did you come across that?~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (self in player) "You already have that.";
                  if (oldMadameSorra in madameSorras) {
                      if (self.takeCrystalBall) {
                          if (oldMadameSorra.spiritsRestless) oldMadameSorra.dontKillSpiritsRestless = true;
                          oldMadameSorra.spiritsRestless = true;
                          "~You anger the spirits,~ she says, pushing you back.";
                      }
                      self.takeCrystalBall = true;
                      "~What are you doing?~ she asks, pushing you back, ~do you try to curse yourself?~";
                  }
                  if (madameSorrasMadameSorra in madameSorras) {
                      if (self.takeCrystalBall) {
                          if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                          madameSorrasMadameSorra.spiritsRestless = true;
                          "~You anger the spirits,~ she says, pushing you back.";
                      }
                      self.takeCrystalBall = true;
                      "~What are you doing?~ she asks, pushing you back, ~do you try to curse yourself?~";
                  }
                  move self to player;
                  "Taken.";
              Pet, Touch:
                  if (self in player) "The ball is smooth and heavy as you play with it.";
                  if (oldMadameSorra in madameSorras || madameSorrasMadameSorra in madameSorras) {
                      <<Take self>>;
                  }
              ThrowAt:
                  if (self in player) {
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "You might need that. Better hold onto it.";
                  }
              Eat:
                  "The crystal is larger than your mouth. You couldn't even try.";
              Taste:
                  "Really? It's crystal that's been pawed on by the old lady.";
              Replace:
                  if (player in basement) {
                      "Since it's clear quartz, it might work, but it's too big to fit in there.";
                  }
                  rfalse;
          ],
          showNick false,
          takeCrystalBall false,
    has   concealed;
