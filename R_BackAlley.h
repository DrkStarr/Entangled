
! ---------------------------------------------------------------------------- !
!       BACK ALLEY. 01/18/18
!
  Room    backAlley "Back Alley"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              if (basement.firstTime) {
                  print "This alley has been spray-painted by vandals. It's
                  places like these where people get murdered. A dumpster sits
                  against the wall of the shop, so full that a bike sticks out of it.";
              } else {
                  print "For being an alley, it's clean back here. There's a side
                  door into the gallery and a dumpster next to it. The back street
                  continues behind the rest of the buildings and is used for garbage pick up.";
              }
              print " The way out of here is northeast.^";
              if (self.curatorLeaving || self.stillHearGallery) {
                  self.curatorLeaving = false;
                  self.stillHearGallery = false;
                  iCuratorLeaving = 0;
                  StopDaemon(self);
                  "^You hear the curator curse to herself as she walks back into the gallery using the side door.";
              }
              if (self.quickEnterGallery) {
                  self.quickEnterGallery = false;
                  "^You hear the curator curse to herself, loud enough to hear it in the alley.";
              }
              rtrue;
          ],
          daemon [;                                        !   Started In Art Gallery
              ! Used in Back Alley description
              if (self.curatorLeaving) {
                  iCuratorLeaving++;
              }
              if (iCuratorLeaving > 2) {
                  iCuratorLeaving = 0;
                  self.curatorLeaving = false;
                  self.stillHearGallery = true;
              }

              ! Used in Listen for Outside Gallery
              if (self.stillHearGallery) {
                  iListenLeaving++;
              }
              if (iListenLeaving > 1) {
                  iListenLeaving = 0;
                  self.stillHearGallery = false;
                  StopDaemon(self);
              }
          ],
          ne_to [;
              PlayerTo(outsideArtGallery);
              rtrue;
          ],
          e_to [;
              <<Enter backAlleyDoor>>;
          ],
          cant_go [;
              "The way out of here is northeast.";
          ],
          before [;
              Exit:
                  PlayerTo(outsideArtGallery);
                  rtrue;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  if (artGallery.brokeCat) "You can hear the curator curse and swear from inside the gallery.";
                  if (basement.firstTime || theTavern.closedUp) "A peaceful drone comes from the city around you. Other than that, it's quiet.";
                  "Music from the bar down the street can even be heard back here.";
              Smell:
                  return PYT();
              Sleep:
                  return roomSleep();
          ],
          stillHearGallery false,
          curatorLeaving false,
          quickEnterGallery false,
          firstTime true;

! 01/18/18

  RoomObj -> backAlleyObj "alley"
    with  name 'back' 'alley' 'area',
          description [;
              <<Look backAlley>>;
          ],
          before [;
              Search:
                  "You look around the alley, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 01/18/18

  Object  -> backAlleyDumpster "dumpster"
    with  name 'garbage' 'dumpster' 'container' 'trash' 'bin' 'top' 'debris' 'refuse',
          before [;
              Climb:
                  "Where are you going to go? There's nothing useful on the roof.";
              Close:
                  "You should leave it alone.";
              Open:
                  "It's already open.";
              Dig:
                  if (basement.firstTime) "You can't dig through the dumpster. It's full.";
                  if (artGallery.brokeCat) <<Take backAlleyShards>>;
                  "You lean in, but the dumpster is empty. The trash has been recently picked up.";
              Enter, Go:
                  if (basement.firstTime) "Now that's just gross.";
                  if (artGallery.brokeCat) <<Take backAlleyShards>>;
                  "You lean in, but the dumpster is empty. The trash has been recently picked up.";
              Search:
                  if (basement.firstTime) "You search around the garbage a bit, but the only thing of value is the bike.";
                  if (artGallery.brokeCat) "A few quartz shards line the bottom of the dumpster - the remains of the cat.";
                  "Searching around the dumpster, the only thing you find are cigarette butts.";
              Examine:
                  if (basement.firstTime)
                      "The dumpster is full, packed with all sorts of debris, but a bike does stick out of the top of it.";
                  if (self.catInDumpster)
                      "Pushed against the gallery, it sits next to the side door. A few quartz shards line the bottom of the dumpster - the remains of the cat.";
                  "Pushed against the wall, the dumpster sits next to the side door for the gallery. A few cigarette butts litter the area.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The dumpster doesn't need to go anywhere.";
              LookUnder:
                  "The dumpster sits flat on the ground. There's no way to look under it.";
          ],
          catInDumpster false,
     has  concealed static container open;

! 06/22/19

  Object  -> backAlleyTattooShop "shop"
    with  name 'tattoo' 'shop' 'building' 'place' 'wall',
          before [;
              Examine, Search:
                  "The building has been painted several times to cover up the graffiti, but the kids keep coming back.";
              Enter, Go:
                  "The way out of here is northeast.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
      has concealed static;

! 07/23/19

  Object  -> backAlleySprayPaint "graffiti"
    with  name 'spray' 'paint' 'painting' 'graffiti',
          before [;
              Examine, Search:
                  "It's freshly painted and of a big middle finger. Telling the world off and tagged by some hoodlum.";
              Enter, Go:
                  "The way out of here is northeast.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
      has concealed static;

! 02/13/18

  Object  backAlleyDoor "door"
    with  name 'side' 'door' 'sidedoor',
          before [;
              Close:
                  "You don't need to do that.";
              Examine, Search:
                  "The side door into the gallery is only used by the curator.";
              Enter, Go, Open:
                  "That door allows the curator access to the alley. The way out of here is northeast.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gallery.";
              Unlock:
                  "The door's already unlocked.";
          ],
      has concealed static;

! 02/13/18

  Object  backAlleyGallery "gallery"
    with  name 'art' 'gallery' 'building' 'place' 'wall' 'shop' 'store',
          before [;
              Examine, Search:
                  return (PrintExamineArtGallery());
              Enter, Go:
                  <<Enter backAlleyDoor>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
      has concealed static;

! 01/18/18

  Object  backAlleyShards "quartz shards"
    with  name 'shard' 'crystal' 'shards' 'clear' 'quartz' 'remain' 'remains' 'cat',
          before [;
              Search:
                  "A few quartz shards line the bottom of the dumpster - the remains of the cat.";
              Examine:
                  "The cat's been shattered. Only a few shards are left.";
              Take, Remove, Pull:
                  if (self.shardTaken) "You already took that.";
                  self.&name-->0 = 'ph000601';
                  self.shardTaken = true;
                  backAlleyDumpster.catInDumpster = false;
                  score = score + 5;
                  move crystalShard to player;
                  "You lean into the dumpster picking up one of the shards.";
              Turn, PushDir, Push:
                  "That won't help.";
          ],
          shardTaken false,
     has  concealed static pluralname;

! 06/22/19

  Object  backAlleyBike "bike"
    with  name 'bike' 'mountain',
          before [;
              Search:
                  if (plate in backAlleyDumpster) "Looking the bike over further, you see the plate says: ~Believe.~ The alien next to it has big eyes.";
                  "You find nothing looking over the bike.";
              Examine:
                  if (plate in backAlleyDumpster) "A mountain bike sticks out of the refuse. On the backend, there's a fake plate attached to it.";
                  "A mountain bike sticks out of the dumpster.";
              Ride:
                  "The bike is stuck in the dumpster and going nowhere.";
              Take, Remove, Pull:
                  "It would be too hard to pull out of the garbage and not worth the effort.";
              Turn, PushDir, Push:
                  "That won't help.";
          ],
     has  concealed static;

! 01/08/20

  Object  backAlleyButts "butts"
    with  name 'cigarette' 'butts' 'butt' 'burnt' 'filter' 'filters',
          before [;
              Examine, Search:
                  "The few butts that lie around are crushed into the ground and smoked to the very end.";
              Take, Remove, Pull, Turn, PushDir, Push:
                  if (self.triedToTake) "You don't need them.";
                  self.triedToTake = true;
                  "There's nothing left but a few filters, and even they're burnt.";
          ],
          triedToTake false,
     has  concealed static pluralname;
