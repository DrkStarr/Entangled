! Tom = 34 Current Time
!
! Tom is crazy about UFOs
!

! Character Diamond
! 1: Manic - Hyper - Ecstatic
! 2: Impressionalbe - Believes In Conspiracy Theroys
! 3: Weak - Has A Bad Heart - Sheltered Growing Up
! 4:


! ---------------------------------------------------------------------------- !
!       TOM. 06/03/19
!
! Age: 34

  Object  -> mapleRoadTom "guy"
    with  name 'tom' 'man' 'guy' 'person' 'sweat' 'face' 'hair',
          describe [;
              rtrue;
          ],
          daemon [;
              if (self.askAboutShower) {
                  iAskTom++;
              }
              if (self.dontKillAskAboutShower) {
                  self.dontKillAskAboutShower = false;
              } else {
                  if (iAskTom > 1) {
                      iAskTom = 0;
                      self.askAboutShower = false;
                  }
              }

              if (self.pushedCharacter) {
                  iPushTom++;
              }
              if (self.dontKillPushedCharacter) {
                  self.dontKillPushedCharacter = false;
              } else {
                  if (iPushTom > 1) {
                      iPushTom = 0;
                      self.pushedCharacter = false;
                  }
              }
          ],
          before [ w1;
              AskCreatureFor:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'name':
                          return AskForNameTom();
                      'change', 'quarters', 'quarter':
                          "~Don't mooch from me. I know a scam when I see one.~";
                  }
                  return TomResponse();
              Examine:
                  "Wearing glasses, this guy is middle-aged and podgy around the middle. A thin patch of squirrelly
                  hair slicks his dome while sweat pours down his pale face.";
              Search, Climb:
                  "I don't think he would care for that.";
              Talk:
                  print "[You can try ";
                  if (self.askAboutGov) {
                      if (self.askAboutUFO) {
                          print "ASK ABOUT ALIENS";
                      } else {
                          print "ASK ABOUT UFOS";
                      }
                  } else {
                      print "ASK ABOUT GOVERNMENT";
                  }
                  print " or ";
                  if (self.askAboutDiner) {
                      print "ASK ABOUT TOWN";
                  } else {
                      print "ASK ABOUT DINER";
                  }
                  print " or ";
                  if (self.askAboutSam) {
                      print "ASK ABOUT ALLEY";
                  } else {
                      print "ASK ABOUT SAM";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (self.askHello) "~Hi.~";
                  self.askHello = true;
                  "~Hi,~ he says, looking at you sideways.";
              Kiss:
                  "~Please don't touch me. I don't like physical contact.~";
              SmellNoun:
                  "You'd look strange smelling him.";
              WaveObject:
                  "~You seem a little excited. I know, it's hard to contain.~";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              Pull, Push, PushDir:
                  if (self.pushedOnce) {
                      if (self.pushedCharacter) self.dontKillPushedCharacter = true;
                      self.pushedCharacter = true;
                      "~You trying to start something?~";
                  }
                  self.pushedOnce = true;
                  "~Hey, who are you pushing?~ the guy says, pushing back.";
              Take:
                  "You know he's not an object?";
              Rub, Touch, Pet:
                  "~Get back. I don't like people touching me.~";
          ],
          life [ w1 w2;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: if (self.askAboutShower) return RemoveTom();
                             if (self.pushedCharacter) "~You're pushing your luck, friend.~";
                             "~I know, right? We'll be on the mothership soon.~";
                      t_no: if (self.askAboutShower) "~Hm. I thought you were going to say yes. Too many people believe him.~";
                            if (self.pushedCharacter) "~That's what I thought.~";
                            "~Why be like that? The mothership is here.~";
                      t_good: "~Yeah. I know. We're finally going away.~";
                      t_bad: "~Don't be afraid. We're going home.~";
                      t_sorry: "~Oh, come on. I thought someone like you would believe, right?~";
                      t_thanks: "~Oh. I try to tell everybody they're coming. The aliens are out there.~";
                      default:
                          return TomResponse();
                  }
              Ask:
                  wn = consult_from;
                  w1 = NextWord();
                  w2 = NextWord();
                  if (w1 == 'flat' ) {
                      if (w2 == 'earth' ) {
                          "~What? Do you believe in that? The Earth's not flat. You must be crazy.~";
                      }
                  }
                  if (w1 == 'area' ) {
                      if (w2 == '51' ) {
                          "~Weird stuff goes on out there in Nevada. I've always wanted to check it out, but I think they moved their operations.~";
                      }
                  }
                  if (w1 == 'hanger' ) {
                      if (w2 == '18' ) {
                          "~Wright-Patterson Air Force Base? They have a whole warehouse full of aliens over there. I can't see how they get away with it. One day they'll pay.~";
                      }
                  }
                  switch (w1) {
                      'halloween', 'samhain':
                          "~Halloween? When the aliens take us away, we'll forget when it is.~";
                      'candy':
                          "~Got any? I could always use a snack.~";
                      'snack':
                          "~Just a little something to eat.~";
                      'warehouse':
                          "~Hanger 18? They have a whole warehouse full of aliens over there. I can't see how the government gets away with it.~";
                      'conspiracy', 'conspiracies':
                          "~I don't believe in conspiracies. Don't believe what people say. At this point, the government is just sinister.~";
                      'chemtrails':
                          "~Oh yeah. I'm sure the government is doing that too. We're screwed. We need the aliens to save us.~";
                      'roswell':
                          "~That's the holy land. First contact for us. And then the government covers it all up. Hm. I got to get out there someday.~";
                      'sam':
                          self.askAboutSam = true;
                          "~I saw him pass through here. He's no help. I couldn't even stop him.
                          Probably ran into the aliens and didn't even know it.~";
                      'bowling', 'alley':
                          "~You don't want to go down there. The mothership is going to land
                          anytime now. And I'm sure she's going to scorch the whole alley in the process.~";
                      'glasses':
                          "~They're a bit thick, but I can see. I know there's a mothership out there if that's what you're asking.~";
                      'mothership', 'ship':
                          "~The lights are becoming more frequent. You might not see them all the
                          time, but the mothership is out there. I'm sure she's going to land anytime now.~";
                      'ufo', 'ufos':
                          self.askAboutUFO = true;
                          "~Check out the lights in the sky. You can see them every now and then. They're fast.
                          That's how you know it's a UFO.~";
                      'landing':
                          "~Oh yeah. They're going land. Probably over at the alley. That parking lot is a waste anyway.
                          But you don't want to go over there. They'll fry you with their engines.~";
                      'parking', 'lot':
                          "~Oh. I'd love to watch the mothership land on all those cars. She'll squash them like ants,
                          something they should've done to this town long ago.~";
                      'government', 'gov':
                          self.askAboutGov = true;
                          print "~Oh yeah. They cover stuff up all the time";
                          if (self.adjustGlasses) {
                              self.adjustGlasses = false;
                              print ",~ he says adjusting his glasses, ~";
                          } else {
                              print ". ";
                          }
                          "They know about the UFOs. Ever watch Ancient Aliens? But now with the
                          mothership coming, there's no way to hide it any longer.~";
                      'alien', 'aliens':
                          if (self.askAboutAliens)
                              "~I follow that stuff on the internet. Some really smart
                              people out there. I've learned that now is the time they're supposed to
                              return according to calendars in Egypt.~";
                          self.askAboutAliens = true;
                          "~The sky is full of them. And they love to take specimens. I hope
                          they take me. I'm ready. When I saw the lights, I started a cleanse.~";
                      'sky', 'light', 'lights':
                          "~If you watch the sky long enough, you can see them. But they're fast.
                          I'm sure there's a mothership out there controlling it all.~";
                      'diner':
                          self.askAboutDiner = true;
                          "~Those people in there don't care about UFOs. They all think I'm crazy.
                          I hear them behind my back. But you look like someone that might understand.~";
                      'city', 'town', 'sunnybrook':
                          "~It's hard in this town. It seems to get smaller by the day. A lot of people have moved on. I would, but I can't afford it.~";
                      'amy', 'clerk':
                          "~The lady that works over at the convenience store? She told me once that
                          she wanted to be a writer. I told her she should do a book on UFOs.
                          She never took my advice. Some writer she is.~";
                      'school', 'schooling', 'college':
                          "~School? I've always learned my lessons the hard way. And who needs it?
                          Just some paper on the wall.~";
                      'bar', 'the', 'tavern':
                          "~The Tavern? I loved hanging out at the place, saw some great bands too,
                          but that's gone now. You know how it is. Times are tight.~";
                      'current', 'date', 'year':
                          "~Hard to believe it's already 2020. I was sure the aliens would come
                          back in 2012. What a bummer that was.~";
                      'doorman':
                          "~Who cares about him. They're going to take us away.~";
                      'judy', 'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          "~Who cares about her. They're going to take us away.~";
                      'nick', 'biker', 'boomer':
                          "~That old biker thinks he knows it all. I've tried to tell him, but he won't listen.
                          When the aliens come, I hope they don't take him.~";
                      'meteor', 'meteors', 'shower', 'showers', 'taurid', 'stream', 'fireball', 'fireballs':
                          if (self.askAboutShower) self.dontKillAskAboutShower = true;
                          self.askAboutShower = true;
                          if (self.askAboutShowerTwice) "~No. You don't believe him do you?~";
                          self.askAboutShowerTwice = true;
                          "~Oh, don't tell me you've been talking to Nick. I know where he stands, and I've tried to help him out,
                          but he's a Boomer.~";
                            'note', 'notes':
                          "~That might be important, but I'm telling you there's a mothership out there. We need to tell someone.~";
                      'scientist':
                          "~Never heard of 'im. But someone that smart must be into UFOs.~";
                      'name':
                          return AskForNameTom();
                      'work', 'job':
                          "~I work out in Springfield. You know that. We take the bus every day.~";
                      'melville', 'melvill':
                          "~After Melville shut its doors, this town started drying up. A lot of people
                          worked in those factories and losing those jobs hurt this city.~";
                      'springfield':
                          "~The only work for miles around. I wish I could move there. Taking the bus every day sucks.~";
                      'bus':
                          "~What about it? We both ride that thing out to Springfield every day. What a long
                          trip. At least I have my phone for the ride. I feel sorry for you.~";
                      'mark', 'attendant', 'gas', 'station':
                          "~Mark's a cool guy, but he just doesn't get it. I've tried to tell him
                          about the aliens. All he cares about are girls.~";
                      'yukypah', 'heef', 'statue':
                          "~You mean the statue in the park? That's something from another time. I'm surprised
                          they haven't taken it down yet.~";
                      'plate':
                          "~What plate are you talking about?~";
                      'tom', 'himself', 'him', 'man', 'guy', 'person':
                          "~People say I'm into conspiracy theories, but I'm not. I just know that
                          the aliens are coming like Ford Prefect in Hitchhiker's Guide.~";
                      'cleanse':
                          "~Uh. That was a little rough. You really don't want to hear about it.~";
                      'ancient':
                          "~Best show on the History Channel. And you know it has to be true. It's on the History Channel.~";
                      'heart':
                          "~Well. My parents always said I have an arrhythmia. But who cares. I'm sure the aliens could take care of that in a minute.~";
                      'me', 'self', 'yourself':
                          "~I've seen you around, on the bus and all, but I don't know anything about you.~";
                      'girls':
                          "~More trouble than they're worth if you ask me.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "~Oh, I'm sure that was cooked up in some government laboratory. We need the aliens now for sure.~";
                      default:
                          return TomResponse();
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          if (self.askAboutShower) return RemoveTom();
                          if (self.pushedCharacter) "~You're pushing your luck, friend.~";
                          "~I know, right? We'll be on the mothership soon.~";
                      'no':
                          if (self.askAboutShower) "~Hm. I thought you were going to say yes. Too many people believe him.~";
                          "~Why be like that? The mothership is here.~";
                      'good':
                          "~Yeah. I know. We're finally going away.~";
                      'bad':
                          "~Don't be afraid. We're going home.~";
                      'sorry':
                          "~Oh, come on. I thought someone like you would believe, right?~";
                      'sky':
                          "You tell him you don't see anything unusual in the sky.^
                          ^~You gotta give it a bit. They pop every now and then. Keep looking.~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned':
                          "He's preoccupied and doesn't care.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'nick', 'biker', 'boomer':
                          if (tattooShopNick.askAboutTom) {
                              self.tellAboutNick = true;
                              "You tell him Nick doesn't believe in UFOs.^
                              ^~I know that. And you better not tell me about the meteor shower.
                              He goes on about that all the time. His type can't believe.~";
                          }
                          "~What about Nick. That guy just gets under my skin.~";
                      'meteor', 'meteors', 'shower', 'showers', 'taurid', 'stream', 'fireball', 'fireballs':
                          return RemoveTom();
                      'ufo', 'ufos':
                          "You tell Tom you don't think they're UFOs.^
                          ^~What proof do you have. They're UFOs. Lights just don't show up in the sky
                          for no reason.~";
                      'mothership', 'mother', 'ship':
                          "You tell Tom you doubt there's a mothership out there.^
                          ^~Like you would know. The government is covering stuff up all the time.
                          I watch Ancient Aliens.~";
                      'thanks', 'thank':
                          "~Oh. I try to tell everybody they're coming. The aliens are out there.~";
                      'evict', 'eviction', 'sam', 'trailer', 'me', 'self', 'yourself':
                          if (self.toldEvict) "You've already told him about that.";
                          self.toldEvict = true;
                          "You tell him the manager over at the trailer park found out Sam was living there.^
                          ^~Wow. He's going to boot you? Don't worry. Just hook up with the aliens. That mothership will touch down any day now.~";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "~I don't want to hear about it. I know the government created it.~";
                      default:
                          "~I don't care. They're going to take us away. What can we do?~";
                  }
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              Give:
                  "~Ah, get out of 'ere.~";
              Open:
                  "~Go push someone else around.~";
              Enter:
                  if (noun == mapleRoadDiner)
                      "~I'm not going back in there 'til the mothership lands. Those people don't care.~";
              Go:
                  if (noun == s_obj) "~I'm not going back in there 'til the mothership lands. Those people don't care.~";
                  "~No way, I'm staying right here until the mothership lands.~";
              Strong: "The guy ignores you.";
          ],
          askHello false,
          askAboutGov false,
          askAboutUFO false,
          askAboutDiner false,
          askAboutSam false,
          askAboutAliens false,
          seenNotes false,
          adjustGlasses true,
          helpTom false,
          askAboutShower false,
          dontKillAskAboutShower false,
          askAboutShowerTwice false,
          tellAboutNick false,
          pushedOnce false,
          pushedCharacter false,
          dontKillPushedCharacter false,
          toldEvict false,
          gavePlate false,
    has   animate male;

  [ TomResponse;
        "~Who cares about that. They're going to take us away.~";
  ];

  [ RemoveTom;
        remove mapleRoadTom;
        remove mapleRoadGlasses;
        score = score + 5;
        mapleRoadTom.helpTom = false;
        mapleRoad.tomGone = true;
        SelfPlayer.scoredTom = true;
        tattooShopNick.askAboutTom = true;
        if (mapleRoadTom.tellAboutNick) {
            print "~What? I tell you that. And you. Oh my god.";
        } else {
            print "~What? You think it's a meteor shower?";
        }
        " You're no better than anybody else in this town. I might as well
        go back inside. You wait. When the mothership touches down, it'll
        change everything.~^
        ^He turns, entering the diner to the south.";
  ];

  [ AskForNameTom;
        SelfPlayer.knowTom = true;
        "~What? Don't you remember me? I'm Tom. You know that.~";
  ];
