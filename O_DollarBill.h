! When the dollar makes it way into the park, if the player doesn't' go right in
! and waits two turns, Eddie will take the dollar and the player will have to ask
! Eddie about the dollar 3 times until he gives it up.
!
! Buy Drink: Causes impaired thinking and slows down motor functions. You shouldn't' waste your money on that.
! Give Sorra the dollar for a reading - No Lifeline

! Put Dollar On Counter in the Convenience Store
! Give the kid the dollar will get rid of him too

! ---------------------------------------------------------------------------- !
!       DOLLAR BILL. 01/09/19
!
  Movabl  dollarBill "dollar bill"
    with  name 'dollar' 'bill' 'buck' 'money',
          after [;
              Drop, Insert:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementTubes || second == brokenTube) "It doesn't belong there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  if (second == theTavernVendingMachine) "It doesn't work like that. It only takes quarters.";
                  if (second == bowlingAlleyArcadeMachine) "It doesn't work like that. It only takes quarters.";
                  if (second == alleyBarCounter) "~You really want to buy a pitcher? I'm telling you these taps are dirty.~";
                  "You don't want to lose that. You might need it.";
          ],
          before [;
              Buy:
                  if (self in player) "You already have that.";
              Insert:
                  if (self in clothes) "It's already in your pocket.";
                  if (second == clothes) {
                      move self to clothes;
                      "You stick the dollar bill in your pocket.";
                  }
              Examine, Search:
                  "It's a bit wrinkled and dog-eared, but it's still worth something.";
              Rub:
                  "It's not a djinni's bottle. You're not going to get three wishes off of it.";
              Touch:
                  "The bill is wet and wrinkled.";
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
                  if (second == theTavernVendingMachine) "It doesn't work like that. It only takes quarters.";
                  if (second == bowlingAlleyArcadeMachine) "It doesn't work like that. It only takes quarters.";
                  if (second == alleyBarCounter) "~You really want to buy a pitcher? I'm telling you these taps are dirty.~";
                  if (second == convenienceStoreCounter) return ShowDollarToClerk();
                  "You don't want to lose that. You might need it.";
              Give:
                  if (second == convenienceStoreAmy) return ShowDollarToClerk();
                  if (second == theTavernNick) "~Looks like you have a little cash, but that's still not enough for a shot.~";
                  if (second == alleyBarPhil) {
                      if (self.giveToPhil) {
                          print "~Like I said. It'll give you the runs for a week";
                          return PhilWash();
                      }
                      self.giveToPhil = true;
                      print "~Look. You don't want a pitcher of this stuff. I'll give you the runs for a week";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~If you're looking to bowl, it's going to cost more than a buck.~";
                  if (second == gasStationJerry) return showDollarToJerry();
                  if (second == theTavernHarry) "~You're paying the wrong guy. It's the bartender you want to tip.~";
                  if (second == smallParkEddie) {
                      madameSorrasMadameSorra.askForBall = true;
                      remove smallParkEddie;
                      remove self;
                      SelfPlayer.gaveEddieDollar = true;
                      if (incense in artGalleryCounter) {
                          remove incense;
                          move babushka to smallPark;
                          "~Thanks. It's not much, but I can get something to drin... I mean, eat.~^
                          ^Getting up, he stretches before walking out of the park. Looking at the bench,
                          you see he was sitting on a scarf.";
                      }
                      "~Thanks. It's not much, but I can get something to drin... I mean, eat.~^
                      ^Getting up, he stretches before walking out of the park.";
                  }
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I'm not selling my incense. I want it back.~";
                      if (artGalleryStatue in artGalleryPedestal)
                          "~A dollar? Is that all you think this statue is worth? It takes years to
                          hone a craft, to make something like this, and you think it's worth only
                          a dollar. Get out of here before I get angry.~";
                      "~We made a deal. I don't need your money.~";
                  }
                  if (second == madameSorrasMadameSorra) {
                      remove self;
                      madameSorrasMadameSorra.seenHands = true;
                      "She takes the dollar from you.^
                      ^~Show me your hands.^^Yes. Yes. Wait...^^I don't see your lifeline.
                      You're not supposed to be here.~^^~This is troubling. I wonder what my mother would do,~
                      she says, ignoring you and returning her gaze to the crystal ball.";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreKid) return GiveDollarToKid();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Show:
                  if (second == alleyBarPhil) {
                      if (self.giveToPhil) {
                          print "~You could get a pitcher for that, but you'd regret it";
                          return PhilWash();
                      }
                      self.giveToPhil = true;
                      print "~You could get a pitcher for that, but you'd have the runs for a week";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~Like. I hope you have more money than that.~";
                  if (second == gasStationJerry) "~Sorry. If you want cigarettes, they're more than a dollar a pack.~";
                  if (second == theTavernNick) "~A dollar doesn't go as far as it used to. Shots here are two bucks a piece.~";
                  if (second == theTavernHarry) "~Flaunting your wealth. Doesn't look like you have much.~";
                  if (second == smallParkEddie) "~Yeah. Too bad you showed up. That dollar would really help.~";
                  if (second == madameSorrasMadameSorra) "~Look. If you vant a reading, then give it to me.~";
                  if (second == convenienceStoreAmy) return ShowDollarToClerk();
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                  if (incense in SelfPlayer) "~I'm not selling my incense. I want it back.~";
                      if (artGalleryStatue in artGalleryPedestal) "~I know you're not making an offer. The statue is worth a lot more.~";
                      "~See. I didn't take all your money.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreKid) return GiveDollarToKid();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              Take:
                  if (self in clothes) {
                      move self to player;
                      "You take the dollar bill from your pocket.";
                  }
                  if (self.dollarScore == false) {
                      self.dollarScore = true;
                      move self to player;
                      "Taken.";
                  }
              Remove:
                  <<Take self>>;
              SmellNoun:
                  if (SmellTest()) rtrue;
                  self.smellDollar = true;
                  "You give it a whiff questioning where it's been.";
              Eat, Taste:
                  if (self.smellDollar) "After smelling it, you know better than that.";
                  "It's been left out in the street. It would taste funky at best.";
              Turn, PushDir, Push, Pull:
                  "You don't need to do that.";
              Pet:
                  "You feel nothing unexpected.";
              ThrowAt:
                  if (self in player) {
                      "It lacks the mass to do any damage.";
                  }
          ],
          daemon [;
              if (self in smallPark && smallParkEddie in smallPark) {
                  iDollarTake++;
                  if (iDollarTake >= 4) {
                      madameSorrasMadameSorra.askForBall = true;
                      SelfPlayer.gaveEddieDollar = true;
                      if (incense in artGalleryCounter) {
                          remove incense;
                          move babushka to smallPark;
                      }
                      remove smallParkEddie;
                      remove self;
                      if (player in outsideTownHall) {
                          "^The bum pushes past you as he comes out of the park. ~Sorry,~ he says
                          before making his way down the street and out of sight.";
                      }
                  }
              }
          ],
          giveToPhil false,
          smellDollar false,
          dollarScore false,
          showToAmy false,
          gaveAmyDollar false,
          showBillToJerry false,
    has   concealed;

  [ GiveDollarBill;
        remove dollarBill;
        convenienceStoreAmy.askAboutComic = false;
        dollarBill.gaveAmyDollar = true;
        move conanComic to player;
        move chocolateBar to player;
        print "~Here's the comic and a snack";
        if (convenienceStoreAmy.saidNoChange) {
            convenienceStoreAmy.saidNoChange = false;
            print ". Sorry. We don't have any change";
        }
        ". Don't worry about the tax,~ she says, handing you the stuff and taking the dollar. ~Enjoy. Conan should be a good read.~";
  ];

  [ GiveDollarToKid;
        convenienceStore.walkIn = false;
        give convenienceStoreAmy ~scenery;
        StopDaemon(convenienceStore);
        remove convenienceStoreKid;
        remove dollarBill;
        "~Yeah, that's worth a comic. Thanks, and I can take a hint.
        You want me out of here. Later.~^
        ^The clerk addresses you as the kid walks out the door. ~Wow, that was
        starting to drive me crazy.~ Taking a second, she wipes off a bit of sweat
        and then returns to her comic book.";
  ];

  [ ShowDollarToJerry;
        if (dollarBill.showBillToJerry) "~The gum in here is old. Go over to the convenience store if you want something.~";
        dollarBill.showBillToJerry = true;
        "~For a dollar? I could sell you a few packs of gum, but I doubt you want them.~";
  ];

  [ ShowDollarToClerk;
        if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
        if (dollarBill.showToAmy) return GiveDollarBill();
        dollarBill.showToAmy = true;
        if (convenienceStoreAmy.askAboutComic) convenienceStoreAmy.dontKillAskAboutComic = true;
        convenienceStoreAmy.askAboutComic = true;
        print "You ask her what you can get for a dollar.^
        ^~I could sell you the Conan comic and a chocolate bar. That's worth a buck";
        if (convenienceStoreAmy.saidNoChange) {
            convenienceStoreAmy.saidNoChange = false;
            ". Sorry. We're out of change.~";
        }
        ".~";
  ];
