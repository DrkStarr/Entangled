
! ---------------------------------------------------------------------------- !
!       PLATE. 06/22/19
!
  Movabl  plate "plate"
    with  name 'fake' 'plate' 'license' 'grey',
          after [;
              Drop, Insert:
                  move self to player;
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
              Rub, Touch:
                  "You rub the plate for a minute, looking into the Grey's big eyes, but it's already clean.";
              Examine, Search:
                  "The plate must be a souvenir from Area 51. It says ~Believe~ with a picture of
                  an alien next to it - a Grey with big eyes.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "The plate doesn't smell even though it was in the garbage.";
              PutOn:
                  move self to player;
                  "You don't want to lose that. You might need it.";
              Give:
                  if (second == mapleRoadTom) return GivePlateTom();
                  if (second == tattooShopNick) return GivePlateNick();
                  if (second == convenienceStoreOldAmy) return GivePlateAmy();
                  if (second == gasStationMark) return GivePlateMark();
                  if (second == oldMadameSorra) "~I do not vant your worldly possessions.~";
                  if (second has pluralname) "They don't seem interested.";
                  if (second has male) "He doesn't seem interested.";
                  if (second has female) "She doesn't seem interested.";
                  if (second == gravelRoadAttendant) "You can't do that from here.";
                  "You better hold on to that.";
              Pull, PushDir, Push:
                  if (self in player) "You don't need to do that.";
                  <<Take self>>;
              Show:
                  if (second == mapleRoadTom) return GivePlateTom();
                  if (second == tattooShopNick) return GivePlateNick();
                  if (second == convenienceStoreOldAmy) return GivePlateAmy();
                  if (second == gasStationMark) return GivePlateMark();
                  if (second == oldMadameSorra) "The old woman pays you no mind as she stares into the crystal ball.";
                  if (second == gravelRoadAttendant) "You can't do that from here.";
              Pet:
                  "You feel nothing unexpected.";
              Tie:
                  if (second == backAlleyBike) "You can't put it back. It broke off when you took it.";
              ThrowAt:
                  if (self in player) {
                      if (second == parkingLotNeonSign) "What do you want to do? Break it some more?";
                      if (second == gasStationSign) "You'd end up breaking the sign and the attendant would see you.";
                      "You might need that. Better hold onto it.";
                  }
              Take:
                  if (self in player) rfalse;
                  move self to player;
                  mapleRoad.exploredTown = true;
                  "Working the plate back and forth for a minute, it breaks away from the bike.";
              Remove:
                  <<Take self>>;
              Eat, Taste:
                  "Definitely solid metal. Something to break your teeth on.";
          ],
          showToAmy false,
          showToMark false,
          showToNick false;

  [ GivePlateTom;
        remove plate;
        remove mapleRoadTom;
        remove mapleRoadGlasses;
        score = score + 5;
        mapleRoad.tomGone = true;
        SelfPlayer.scoredTom = true;
        mapleRoadTom.helpTom = false;
        mapleRoadTom.gavePlate = true;
        "He takes the plate from you.^
        ^~I guess you do believe. I'm not the only one in this town. I knew it.
        Thanks. I'm going to have to put this up on my bedroom wall. And it'll
        drive those people in the diner crazy.~ Smiling, he returns to the restaurant.";
  ];

  [ GivePlateNick;
        if (plate.showToNick) "~Like I said, you should show that to Tom.~";
        plate.showToNick = true;
        "~Where did you find that,~ the old biker says, laughing to himself.
        He looks it over for a bit.
        ~You should show that to Tom. I bet he'd love it,~ he says, handing it back.";
  ];

  [ GivePlateAmy;
        if (convenienceStoreOldAmy.lookUp) convenienceStoreOldAmy.dontKillLookUp = true;
        convenienceStoreOldAmy.lookUp = true;
        if (plate.showToAmy) "~I don't know why you think I'm into aliens. Try Tom. He would love it.~";
        plate.showToAmy = true;
        "~That's a cute trinket,~ she says, handing it back. ~You know I bet Tom would love it.~";
  ];

  [ GivePlateMark;
        gasStationMark.eyesOpen = true;
        if (plate.showToMark) "~I don't want it. Try giving it to someone else.~";
        plate.showToMark = true;
        "~Why are you showing me that? I don't want it,~ the attendant says from inside the booth.
        ~Give it to someone who'd appreciate it.~";
  ];
