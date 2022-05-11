
! ---------------------------------------------------------------------------- !
!       RUSTY GATE. 5/30/17
!
  Room    rustyGate "Rusty Gate"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
                  print "The path comes to an end at a rusty gate";
              } else {
                  print "You stand in front of a rusty gate";
              }
              SelfPlayer.outside = true;
              print ". Broken down vehicles litter the yard behind it. The sign on the fence reads,
              ~Trespassers Will Be Shot.~ To the southwest is Maple Road.^^";
              if (rustyGateDog.eatingJerky) {
                  self.dogBarking = false;
                  "In the yard, there's a dog trying to open a sealed beef pack.";
              } else {
                  self.dogBarking = true;
                  "The yard's protected by a dog, he bares his teeth and barks at your presence.";
              }
          ],
          n_to [;
              if (rustyGateDog.eatingJerky) <<Enter rustyGateRustyGate>>;
              "Stepping towards the gate, the dog reacts violently barking even louder. You stop. The Doberman doesn't relent.";
          ],
          sw_to [;
              <<Enter rustyGateMapleRoad>>;
          ],
          cant_go [;
              if (rustyGateDog.eatingJerky) "You can go southwest back to Maple Road or north through the gate.";
              "You can go southwest back to Maple Road.";
          ],
          before [;
              GoIn:
                  if (rustyGateDog.eatingJerky) <<Enter rustyGateRustyGate>>;
                  "Stepping towards the gate, the dog reacts violently barking even louder. You stop. The Doberman doesn't relent.";
              Exit:
                  <<Enter rustyGateMapleRoad>>;
              Listen:
                  if (rustyGateDog.eatingJerky == false) "The dog is insane with anger. His barking tries to alert the owner.";
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "The dog has stopped barking. He's busy chewing through the plastic.";
              Smell:
                  return PYT();
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          lookFirstTime true,
          dogBarking false;

! 5/30/17

  RoomObj -> rustyGateObj "area"
    with  name 'area' 'path' 'trail',
          description [;
              <<Look rustyGate>>;
          ],
          before [;
              Follow:
                  <<Enter rustyGateMapleRoad>>;
              Search:
                  "You look around the path a bit, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 5/30/17

  Object  -> rustyGateRustyGate "rusty gate"
    with  name 'rusty' 'gate' 'fence',
          before [;
              Climb:
                  if (rustyGateDog.eatingJerky) {
                      print "You climb over the gate into the yard watching the dog closely.^";
                      PlayerTo(junkYard);
                      rtrue;
                  }
                  <<Open self>>;
              Close:
                  if (self has open) {
                      give self ~open;
                      "You close the gate.";
                  }
                  "That's already closed.";
              Enter, Go:
                  if (rustyGateDog.eatingJerky) {
                      if (self has open) {
                      } else {
                          give self open;
                          print "(first opening the gate)^";
                      }
                      print "You walk through the gate into the yard, keeping a close eye on the dog.^";
                      PlayerTo(junkYard);
                      rtrue;
                  }
                  <<Open self>>;
              JumpOver:
                  if (rustyGateDog.eatingJerky) {
                      print "You jump over the gate, barely clearing it as you watch the dog carefully.^";
                      PlayerTo(junkYard);
                      rtrue;
                  }
                  <<Open self>>;
              Kick:
                  if (rustyGateDog.eatingJerky)
                      "You kick at the gate, but the Doberman doesn't notice. He's too busy trying to open the sealed beef pack.";
                  <<Open self>>;
              Knock:
                  if (rustyGateDog.eatingJerky)
                      "You rattle the gate, but the Doberman doesn't notice. He's too busy trying to open the sealed beef pack.";
                  <<Open self>>;
              Open, PushDir, Push, Pull:
                  if (rustyGateDog.eatingJerky) {
                      if (self has open) "The gate is already open.";
                      give self open;
                      "You open the gate, but the dog doesn't notice.";
                  }
                  "Moving towards the gate, the dog reacts violently barking even louder. You stop, but the Doberman doesn't relent.";
              Examine, Search:
                  if (rustyGateDog.eatingJerky) {
                      print "The gate is ";
                      if (self has open) print "open";
                      else print "closed";
                      " with a rusty old sign attached to it.";
                  }
                  "The gate is rusted with an old sign attached to it. Closed, it's something between you and the dog.";
              Read:
                  <<Read rustyGateSign>>;
              Take, Turn, Remove:
                  "The rusty gate doesn't need to go anywhere.";
          ],
     has  concealed static openable ~open supporter;

! 5/30/17

OutRchDog  -> rustyGateDog "dog"
    with  name 'dog' 'hound' 'mutt' 'doberman' 'dobermann' 'pinscher',
          before [;
              Enter, Go:
                  if (self.eatingJerky) <<Enter rustyGateRustyGate>>;
                  "Moving towards him, the dog reacts violently barking even louder. You stop. The Doberman doesn't relent.";
              Examine:
                  if (self.eatingJerky) "The dog gnaws at the plastic that protects the meat inside the sealed package.";
                  "The dog barks at you. A Doberman Pinscher trained to protect the yard.";
              Pet:
                  if (self.eatingJerky) "Ever pet a dog while he was eating? It's a good way to lose a hand.";
                  "If you reached over to pet him, he'd take your arm off.";
              Eat, Taste:
                  "That dog would eat you before you ate it.";
              Talk:
                  if (self.eatingJerky) "The dog pays no attention to you as he gnaws at the plastic.";
                  "The dog puts on a show of force, barking at you.";
          ],
          life [;
              if (self.eatingJerky) "The dog pays no attention to you as he gnaws at the plastic.";
              "The dog stands there barking at you.";
          ],
          orders [;
              if (self.eatingJerky) "The dog pays no attention to you as he gnaws at the plastic.";
              "The dog stands there barking at you.";
          ],
          eatingJerky false,
     has  animate male;

! 5/30/17

  OutRch  -> rustyGateYard "yard"
    with  name 'junk' 'yard' 'junkyard' 'car' 'cars' 'vehicle' 'vehicles' 'scrap' 'automobile' 'automobiles' 'auto' 'autos' 'lorry',
          before [;
              Examine:
                  "The yard is full of broken-down cars. Different makes and models. All leftover for scrap.";
              Enter:
                  <<Enter rustyGateRustyGate>>;
          ];

! 5/30/17

  OutRch  -> rustyGateMapleRoad "Maple Road"
    with  name 'maple' 'gravel' 'road',
          before [;
              Enter, Go:
                  PlayerTo(mapleRoad);
                  rtrue;
              Examine:
                  "Maple Road runs east to west. It meets up with Main Street on the eastside.";
          ];

! 3/06/19

  Object  -> rustyGateSign "sign"
    with  name 'sign' 'wire' 'ties' 'sheet' 'metal' 'tie' 'rusty' 'old',
          before [;
              Attack, Cut:
                  "The ties are made of metal. Thick as the fence. You're not going to break them.";
              Climb:
                  if (rustyGateDog.eatingJerky) {
                      print "You climb over the gate into the yard watching the dog closely.^";
                      PlayerTo(junkYard);
                      rtrue;
                  }
                  "Moving towards the gate, the dog reacts violently barking even louder. You stop. The Doberman doesn't relent.";
              Enter, Go:
                  if (rustyGateDog.eatingJerky) {
                      if (rustyGateRustyGate has open) {
                      } else {
                          give rustyGateRustyGate open;
                          print "(first opening the gate)^";
                      }
                      print "You walk through the gate into the yard watching the dog closely.^";
                      PlayerTo(junkYard);
                      rtrue;
                  }
                  "Moving towards the gate, the dog reacts violently barking even louder. You stop. The Doberman doesn't relent.";
              Examine, Search:
                  "The sign is a rusted piece of sheet metal. Scrawled across it in red paint, it says: ~Trespassers Will Be Shot.~";
              JumpOver:
                  if (rustyGateDog.eatingJerky) {
                      print "You jump over the gate into the yard watching the dog closely.^";
                      PlayerTo(junkYard);
                      rtrue;
                  }
                  "Moving towards the gate, the dog reacts violently barking even louder. You stop. The Doberman doesn't relent.";
              Kick:
                  if (rustyGateDog.eatingJerky)
                      "You kick at the gate, but the Doberman doesn't notice. He's too busy trying to open the sealed beef pack.";
                  "Moving towards the gate, the dog reacts violently barking even louder. You stop. The Doberman doesn't relent.";
              Read:
                  "It reads, ~Trespassers Will Be Shot.~ It would seem that the owner is armed.";
              Take, Turn, Remove, PushDir, Push, Pull:
                  "The sign's secured to the fence. Thick ties twist around, holding it in place.";
          ],
    has   concealed static;

  [ ObjectRustyGateDog;
        if (rustyGateDog.eatingJerky) "The dog pays no attention to you.";
        print "The dog continues to bark at you, breaking the ";
        if (SelfPlayer.eveningTime || SelfPlayer.nightTime) print "still of the night";
        else print "quiet of the city";
        ". If you don't do something soon, someone is going to come out.";
  ];
