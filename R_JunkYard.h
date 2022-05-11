
! ---------------------------------------------------------------------------- !
!       JUNKYARD. 11/28/17
!
  Room    junkYard "Miller's Yard"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              print "Cars from all over the area end up in this automobile graveyard. Other pieces of junk are
              lying around too, like an old television set with the CRT busted in. Through a row of cars to the
              north lies a small shack. South a";
              if (rustyGateRustyGate has open) {
                  print "n open";
              } else {
                  print " closed";
              }
              " gate.^^A Doberman struggles with a sealed beef pack.";
          ],
          n_to [;
              <<Enter junkYardShack>>;
          ],
          s_to [;
              <<Enter junkYardRustyGate>>;
          ],
          cant_go [;
              "You can go south.";
          ],
          before [;
              Exit:
                  <<Enter junkYardRustyGate>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "The dog has stopped barking and is busy chewing through the plastic to get to the meat.";
              Smell:
                  return PYT();
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          lookFirstTime true;

! 11/28/17

  RoomObj -> junkYardObj "yard"
    with  name 'area' 'yard' 'junkyard' 'graveyard' 'place',
          description [;
              <<Look junkYard>>;
          ],
          before [;
              Search:
                  "You look around the ground a bit, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 11/28/17

  OutRch  -> junkYardRustyGate "rusty gate"
    with  name 'rusty' 'gate' 'fence',
          before [;
              Climb:
                  if (rustyGateRustyGate has open) {
                      print "You climb over the gate even though it's open.^";
                  } else {
                      print "You climb over the gate, leaving the dog behind.^";
                  }
                  PlayerTo(rustyGate);
                  rtrue;
              Enter, Go:
                  if (rustyGateRustyGate has open) {
                  } else {
                      print "(first opening the gate)^";
                  }
                  give rustyGateRustyGate ~open;
                  print "You leave the junkyard slipping through the gate and closing it behind you.^";
                  PlayerTo(rustyGate);
                  rtrue;
              Examine:
                  print "It's rusted and beat up and ";
                  if (rustyGateRustyGate has open) "open.";
                  "closed.";
              Close:
                  if (rustyGateRustyGate has open) {
                      give rustyGateRustyGate ~open;
                      "You close the gate, locking you in with the dog.";
                  }
                  "That's already closed.";
              JumpOver:
                  print "You jump over the gate, barely clearing it.^";
                  PlayerTo(rustyGate);
                  rtrue;
              Open:
                  if (rustyGateRustyGate has open) "That's already open.";
                  give rustyGateRustyGate open;
                  "You open the gate, but the dog stays on the wrapper.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The gate doesn't need to go anywhere.";
          ],
     has  concealed static;

! 11/28/17

  Object  -> junkYardDog "dog"
    with  name 'dog' 'hound' 'mutt' 'doberman' 'dobermann' 'pinscher',
          before [;
              Examine:
                  "The dog bites and gnaws at the plastic, getting a piece of meat now and then.";
              Search:
                  "You don't need to get that close.";
              Kick:
                  "You think about it, but the dog would take your leg off if you tried.";
              Pet, Turn, PushDir, Push, Pull:
                  "Have you ever touched a dog when he was eating? He'd take your arm off.";
              Eat, Taste:
                  "The dog would eat you before you ate it.";
              Go, Enter:
                  "You are already here.";
          ],
          life [;
              "The dog pays no attention to you as he gnaws at the plastic.";
          ],
          orders [;
              "The dog pays no attention to you as he gnaws at the plastic.";
          ],
     has  animate male concealed;

! 11/29/17

  Object  -> junkYardCars "cars"
    with  name 'car' 'cars' 'vehicle' 'vehicles' 'scrap' 'metal' 'automobile' 'automobiles' 'auto' 'autos' 'lorry' 'broken-down',
          before [;
              Examine:
                  "The yard is full of broken-down cars. Different makes. Different models.
                  All stacked up on top of each other forming rows of scrap metal.";
              Search, Enter, Go:
                  "You can't get inside because the cars are stacked on top of each other.";
              Climb:
                  "You might risk knocking them over.";
              Open, Close:
                  "The cars are stacked on top of each other. You can't do that.";
              Push, PushDir:
                  "It would be fun, but the owner would come out with a shotgun.";
              Take, Remove, Turn, Pull:
                  "The cars don't need to go anywhere.";
          ],
     has  concealed static pluralname;

! 01/13/19

  Object  -> junkYardHoods "hoods"
    with  name 'hood' 'hoods',
          before [;
              Examine:
                  "You can't see any of the hoods with the cars stacked on top of each other.";
              Open, Search, Enter, Go:
                  "You can't access any of the hoods. The cars are stacked on one another.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The cars don't need to go anywhere.";
          ],
     has  concealed static pluralname;

! 12/27/17

  Object  -> junkYardTV "television"
    with  name 'discarded' 'television' 'tv' 'broken' 'crt' 'set' 'old' 'part' 'parts' 'junk' 'telle' 'tele',
          before [;
              Close:
                  "The back cover for the television is missing.";
              Examine:
                  if (self.tvTurned) {
                      if (theTavernMarshall.removedVacuumTube) "Slightly turned to the side, the television has a row of broken tubes in the back.";
                      if (self.removedVacuumTube) "Slightly turned to the side, the television is missing a vacuum tube in the back.";
                      "Slightly turned to the side, the television has an exposed row of vacuum tubes in the back.";
                  }
                  "The discarded television's CRT is broken. Now just a box of used parts.";
              Take, Remove:
                  "It's big and bulky. There's no reason to carry it around.";
              Push, Search, Turn:
                  if (theTavernMarshall.removedVacuumTube) {
                      if (self.tvTurned) "You've already done that, revealing a row of broken tubes.";
                      self.tvTurned = true;
                      "You turn the television exposing a row of broken vacuum tubes.";
                  }
                  if (self.removedVacuumTube) "You've already done that. A vacuum tube is missing from the back.";
                  if (self.tvTurned) "You've already done that, leaving a row of old vacuum tubes exposed.";
                  self.tvTurned = true;
                  move vacuumTubeTV to self;
                  "You turn the television exposing a row of vacuum tubes in the back.";
              Open:
                  if (self.tvTurned) "The television is open in the back.";
                  "The television is open in the back. If you want to see inside, you need to turn it.";
              Pull:
                  "There's no need to pull the television around.";
              PushDir:
                  "There's no need to push the television around.";
          ],
          tvTurned false,
          removedVacuumTube false,
     has  concealed static container open;

! 01/01/18

  OutRch  -> junkYardShack "shack"
    with  name 'small' 'shack' 'building' 'shed',
          before [;
              Enter, Go:
                  "The sign did say, ~Trespassers Will Be Shot.~ Maybe you shouldn't test fate.";
              Examine:
                  "The small shack sits upon a hill, and the owner would take a shotgun
                  to you if he found you out here.";
          ],
     has  concealed static;

! 01/01/18

  Object  -> junkYardRows "rows"
    with  name 'row' 'rows',
          before [;
              Examine, Search:
                  "Cars are parked bumper to bumper, forming tight rows with them lined up.";
              Take, Remove:
                  "You can't do that.";
              Turn, PushDir, Push, Pull:
                  "The cars don't need to go anywhere.";
          ],
     has  concealed static pluralname;

! 01/03/18

  Object  -> junkYardBeefJerky "beef pack"
    with  name 'sealed' 'beef' 'jerky' 'stick' 'plastic' 'meat' 'pack' 'package' 'wrapper',
          before [;
              Examine:
                  "The dog munches on the sealed beef pack trying to get through the plastic.";
              Search:
                  "You don't need to get that close.";
              Kick, Pull, Remove, Take, Rub, PushDir, Push, Turn:
                  "The dog growls as you approach. Stepping back, the dog returns to the meat.";
              Open, Close:
                  "The dog would take your arm off if you tried.";
          ],
     has  concealed static;

! 8/27/19

  OutRch  -> junkYardSign "sign"
    with  name 'sign' 'wire' 'ties' 'sheet' 'metal',
          before [;
              Attack:
                  "The ties are made of metal. Thick as the fence. You're not going to break them.";
              Climb:
                  <<Climb junkYardRustyGate>>;
              Enter, Go:
                  <<Enter junkYardRustyGate>>;
              Examine, Search:
                  "The sign is a rusted piece of sheet metal. You can only see the back of it from this side of the fence.";
              JumpOver:
                  <<JumpOver junkYardRustyGate>>;
              Read:
                  "You only see the back. You can't read it from here.";
              Take, Turn, Remove, PushDir, Push, Pull:
                  "The sign's secured to the fence. Thick ties twist around, holding it in place.";
          ],
     has  concealed static;
