
! ---------------------------------------------------------------------------- !
!       BABUSHKA. 01/15/18
!
  Movabl  babushka "scarf"
    with  name 'babushka' 'scarf' 'headscarf' 'stole' 'muffler' 'tippet' 'kerchief' 'bandanna' 'floral' 'pattern' 'dirt',
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
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Examine, Search:
                  if (self in smallPark) "The scarf's been discarded, left behind on one of the benches.";
                  "It's adorned in a colorful floral pattern and made from thick fabric.
                  But the dirt's worn in. The scarf sat outside for too long.";
              Rub:
                  "You are not going to be able to clean it. The dirt isn't coming off, it's worn in.";
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
              Give:
                  if (second == madameSorrasMadameSorra) return (GiveSorraBabushka());
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~I don't know. It must be someone else's. Right?~";
                  }
                  if (second == alleyBarPhil) {
                      print "~It might make for a good rag, but I got plenty of those around here. You keep it";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) "~Maybe if I was doing a primitive exhibit, that would work. But I want something a little more exotic.~";
                  if (second == alleyRentalNancy) "~I know you're not, like, trying to give that to me. It's dirty.~";
                  if (second == gasStationJerry) "~I'm not sure what you're up to, but take it somewhere else.~";
                  if (second == theTavernNick) "~No. Look at that. It's trash. You probably found it.~";
                  if (second == theTavernHarry) "~What am I going to do with that?~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~That's dirty. Plus. I'm sure it's the old fortune-teller's. I want nothing to do with her curses.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Show:
                  if (second == madameSorrasMadameSorra) return (GiveSorraBabushka());
                  if (second == alleyBarPhil) {
                      print "~Not my type of thing, but if it works for you";
                      return PhilWash();
                  }
                  if (second == convenienceStoreKid) "The kid ignores you while trying to convince the clerk.";
                  if (second == alleyRentalNancy) "~I like the floral pattern, but God, like, clean it first.~";
                  if (second == gasStationJerry) "~That's dirty. It looks like you found it in the garbage.~";
                  if (second == theTavernNick) "~Finding all sorts of junk, aren't you?~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~That's pretty. A little dirty. Oh, well. What are you going to do with that?~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Interesting floral pattern. But a little dated. It looks like something I've
                      seen that old fortune-teller wear.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "It reeks of a strong putrid odor, and a musty smell lingers underneath the stench.";
              Pull, PushDir, Push, Turn:
                  "You don't need to do that.";
              Wear:
                  "You could, but it's not that cold.";
              Pet, Touch:
                  "It's soft to the touch.";
              Remove:
                  <<Take self>>;
              ThrowAt:
                  if (self in player) {
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "It lacks the mass to do any damage.";
                  }
              Eat, Taste:
                  "That's not a thing you want to chew on.";
          ],
    has   concealed;

  [ GiveSorraBabushka;
        remove babushka;
        StopDaemon(madameSorrasMadameSorra);
        remove madameSorrasMadameSorra;
        remove madameSorrasAfghan;
        madameSorrasSign.signOn = false;
        madameSorrasSign.&name-->5 = 'ph00043';
        madameSorrasSign.&name-->6 = 'ph00044';
        madameSorrasSign.&name-->7 = 'ph00045';
        "~My babushka. Vhere has it been all this time? No mind. This scarf vas my mother's.
        Before she died, she gave it to me to remind me of the homeland. You have made an old lady
        very happy. Take vut I have. I tired of this life long ago. It's time for me to move on.~
        ^^Madame Sorra gets up, bending over to turn off the neon sign. With a flick of her wrist,
        the light goes out. She straightens back up, looking over at you, whispers something to herself
        and then heads out the door. Looking at the spot where she was, you notice she left behind
        the crystal ball.";
  ];
