
! ---------------------------------------------------------------------------- !
!       OLD SORRA. 06/10/19
!
! Age: 103

  Object  -> oldMadameSorra "Madame Sorra"
    with  name 'madame' 'sorra' 'woman' 'lady' 'old' 'gypsy' 'fortune-teller' 'fortune' 'teller' 'cracks' 'flesh',
          describe [;
              rtrue;
          ],
          daemon [;
              ! Used to get Madame Sorra to respond to asking for a reading / response Yes

              if (self.askForReading) {
                  iAskWait++;
              }
              if (self.dontKillAskForReading) {
                  self.dontKillAskForReading = false;
              } else {
                  if (iAskWait > 1) {
                      iAskWait = 0;
                      self.askForReading = false;
                  }
              }

              ! Used to listen to the spirits being restless / response Sorry
              if (self.spiritsRestless) {
                  iAskRestless++;
              }
              if (self.dontKillSpiritsRestless) {
                  self.dontKillSpiritsRestless = false;
              } else {
                  if (iAskRestless > 1) {
                      iAskRestless = 0;
                      self.spiritsRestless = false;
                  }
              }
          ],
          before [ w1;
              AskCreatureFor:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'name':
                          return AskForNameOldSorra();
                      'palm', 'reading':
                          return OldSorraReading();
                      'crystal', 'ball':
                          "~I vill not just give it up. You have no idea how many have wanted it.
                          My mother knew vhat she vus doing.~";
                      'change', 'quarters', 'quarter':
                          "~Vhy are you concerned? Are you looking to be rich?~";
                      'bill', 'dollar', 'buck':
                          "~That is not how it works. You give me one and vill tell you your future.~";
                  }
                  return OldSorraResponse();
              Examine:
                  "Clutching at the afghan wrapped around her, the old lady can barely stay warm from the
                  fall weather creeping in. Cracks are worn deep into her flesh, and her hands are knotted
                  with arthritis.";
              Search, Climb:
                  "I don't think she would care for that.";
              Rub, Touch, Pet:
                  "You don't want to touch her. She's ancient and might fall apart.";
              Talk:
                  print "[You can try ";
                  if (self.askAboutReading) {
                      print "ASK ABOUT BALL";
                  } else {
                      print "ASK ABOUT READING";
                  }
                  print " or ";
                  if (self.askAboutCity) {
                      print "ASK ABOUT FUTURE";
                  } else {
                      print "ASK ABOUT CITY";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (self.askForReading) self.dontKillAskForReading = true;
                  self.askForReading = true;
                  "~Good evening. I do readings for a dollar. Looking to have your future read?~";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              Kiss, SmellNoun:
                  "That's creepy.";
              WaveObject:
                  "~Don't make it hard on an old lady. I see your hands, but show me them.";
              Take:
                  "You know she's not an object?";
              Push, Pull:
                  "~Do you not know how old I am? Quit.~";
          ],
          life [ w1;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: if(self.askForReading) "~It vill be a dollar before I expend my life force on you.~";
                             "~Hmm. I vill ponder that.~";
                      t_no: if (self.spiritsRestless) self.dontKillSpiritsRestless = true;
                            self.spiritsRestless = true;
                            "~You make the spirits restless.~";
                      t_good: "~Then share your vell being.~";
                      t_bad: "~Yes. I see a dark horizon.~";
                      t_sorry: if (self.spiritsRestless) "~Mere verds vill not quiet them down.~";
                               "~Is your guilt overcoming you?~";
                      t_thanks:
                          "~It is my way. I try to help.~";
                      default:
                          return OldSorraResponse();
                  }
              Ask:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'halloween', 'samhain':
                          "~Yes. Samhain. Vhen the full moon rises twice this month, it will be upon us. Pay me a dollar, and I vill tell you how to protect yourself.~";
                      'candy':
                          "~I do not poison myself vith garbage.~";
                      'arthritis':
                          "~It has set in deep and eats at my bones~";
                      'sign', 'symbol':
                          "~Yes. It is a symbol of my power. Please respect it and leave it alone.~";
                      'dollar', 'bill':
                          "~I charge a dollar for my readings. A fair price for a rare gift.~";
                      'current', 'date', 'year':
                          "~Troubling times we live in. My mother vould roll in her grave.~";
                      'yukypah', 'heef':
                          "~Vhy are you concerned about him?~";
                      'crystal', 'ball':
                          if (self.askAboutCrystal) "~Like I said, this vus my mother's.~";
                          self.askAboutCrystal = true;
                          "~This crystal ball vus my mother's. God rest her soul. I have had it forever.
                          They vill bury me vith it because I have no one to pass it on to.~";
                      'name':
                          return AskForNameOldSorra();
                      'work', 'job', 'shop', 'place':
                          "~My family has done this for generations, but I have no one to pass it on to.
                          Soon it vill all die vith me.~";
                      'scarf',  'babushka', 'headscarf', 'stole', 'muffler', 'tippet', 'kerchief', 'bandanna':
                          "~Hmm. My memory is foggy at my age. I can't say I recall that.~";
                      'mother':
                          "~My mother? No one has ask about her in a long time. She came from Romania, and
                          lived through a dark time. She taught me all I know.~";
                      'romania', 'motherland':
                          "~Yes. The motherland. I vill never make it back now. I vill die in this
                          cursed country.~";
                      'scry', 'scrying':
                          if (self.askForReading) self.dontKillAskForReading = true;
                          self.askForReading = true;
                          "~Do you not see the sign in the window. I read the future. If you can not see that, you are
                          truely lost.~";
                      'city', 'town', 'sunnybrook':
                          self.askAboutCity = true;
                          "~It's a cold place. I've lived here too long and the people have harden.
                          I should have moved on long ago. Now it's too late.~";
                      'spirit', 'spirits':
                          "~Spirits surround this place. Surround this town. You don't want to make them angry.~";
                      'springfield':
                          if (self.askSpringfield) "~That town plays not role in your future.~";
                          self.askSpringfield = true;
                          "~I can tell you this. That town plays not role in your future.~";
                      'satan':
                          "~Do not mention him.~";
                      'reading', 'readings', 'palm':
                          return OldSorraReading();
                      'lifeline', 'life', 'line':
                          if (self.askForReading) self.dontKillAskForReading = true;
                          self.askForReading = true;
                          "~Vut about your lifeline? Do you vaunt a reading?~";
                      'hand', 'hands':
                          if (self.askForReading) self.dontKillAskForReading = true;
                          self.askForReading = true;
                          "~Vut about your hands? Do you vaunt a reading?~";
                      'fortune':
                          "~I only ask for a dollar. It is not much. I vill tell you your fortune.
                          A small amount to pay to know how well-off you're going to be.~";
                      'future', 'self':
                          "~Yes. Give me a dollar and I vill tell you your future. Your path is clouded
                          and you need guidance.~";
                      'night':
                          "~Your path is twisted and in flux. Only God knows how it will end.~";
                      'guidance':
                          "~I can only show you the vay. You can choose to follow it or not.~";
                      'madame', 'sorra', 'gypsy', 'herself', 'fortune-teller', 'fortune', 'teller', 'her', 'woman', 'lady':
                          "~I'm a gifted fortune teller that comes from a long line of scryers.
                          I can see you're trouble.~";
                      'park':
                          "~I don't go over to the park anymore. My bones von't make it.~";
                      'yukypah', 'heef':
                          "~Vhy are you concerned about him?~";
                      'statue', 'melville', 'melvill':
                          "~Vhy are you concerned about it?~";
                      'change', 'quarters', 'quarter':
                          "~Vhy are you concerned, are you looking to be rich?~";
                      'alley', 'library', 'school', 'post', 'office', 'pharmacy', 'complex', 'high-rise', 'highrise', 'highland', 'towers', 'bus', 'apartment', 'apartments':
                          "~Vhy? It does not factor in your future.~";
                      'the', 'tavern', 'bar', 'gas', 'station', 'art', 'gallery':
                          "~Vhy? It shouldn't factor into your future.~";
                      'convenience', 'drug', 'store', 'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s', 'spark', 'plug', 'vacuum', 'tube', 'tubes', 'shard', 'house', 'abandoned', 'home', 'dog', 'doberman', 'fuse':
                          "~I vill need to do a reading first.~";
                      'curator', 'sarah':
                          "~Sarah? I don't recall vhat happened to her. One day she
                          vus gone and that made me very happy.~";
                      'nancy', 'judy', 'amy', 'girl', 'mabel':
                          "~I do not know this person. Vhy do you ask about her?~";
                      'sam', 'phil', 'harry', 'guy', 'nick', 'pretty', 'boy', 'doorman', 'mark', 'jerry', 'scientist', 'tom':
                          "~I do not know this person. Vhy do you ask about him?~";
                      'bartender':
                          "~I don't know this person. Are you craving a drink? Let me see your hands.~";
                      'attendant', 'clerk':
                          "~I don't know this person. Are you craving something you don't understand?
                          Let me see your hands.~";
                      'power':
                          "~I come from a long line of fortune-tellers and can see deep into the future. Your path is twisted, be careful tonight.~";
                      'practice':
                          "~Long have I stared into this ball, having passed none of it on. I failed my Mother for the gift that she gave me.~";
                      'gift':
                          "~Yes. My gift is rare. I should have passed it on long ago. Now I'm stuck in this city.~";
                      'god':
                          "~Do not speak lightly of God. It is a commandment.~";
                      'devil':
                          "~Do not speak such blasphemies in my house.~";
                      'hell':
                          "~Do not blaspheme in my house.~";
                      'path':
                          "~Ve all walk one, but no one listens. I try to point people in the right direction, but they never follow.~";
                      'me', 'self', 'yourself':
                          "~You are trouble in these dark times. I can see it around you. Something blocks your path.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      'pass', 'passing':
                          "~Yes. My mother showed me the art, but I have failed to teach anyone. Now it's just a burden.~";
                      'machine', 'notes': "You better keep that bit of information to yourself.";
                      'ufo', 'ufos', 'alien', 'aliens':
                          if (self.askForReading) self.dontKillAskForReading = true;
                          self.askForReading = true;
                          "~UFOs are not real. Even I know that. Trust in my power. I can do divine things.~";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "~Danger lurks around every corner. Only I can see your future. Pay me a dollar, so you may know.~";
                      default:
                          return OldSorraResponse();
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          if(self.askForReading) "~It vill be a dollar before I expend my life force on you.~";
                          "~Hmm. I vill ponder that.~";
                      'no':
                          if (self.spiritsRestless) self.dontKillSpiritsRestless = true;
                          self.spiritsRestless = true;
                          "~You make the spirits restless.~";
                      'good':
                          "~Then share your vell being.~";
                      'bad':
                          "~Yes. I see a dark horizon.~";
                      'sorry':
                          if (self.spiritsRestless) "~Mere verds vill not quiet them down.~";
                          "~Is your guilt overcoming you?~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned':
                          "You better keep that bit of information to yourself.";
                      'ufo', 'ufos', 'alien', 'aliens':
                          if (self.askForReading) self.dontKillAskForReading = true;
                          self.askForReading = true;
                          "~UFOs are not real. Even I know that. Trust in my power. I can do divine things.~";
                      'thanks', 'thank':
                          "~It is my way. I try to help.~";
                      'evict', 'eviction', 'sam', 'trailer', 'me', 'self', 'yourself':
                          if (self.toldEvict) "You've already told her about that.";
                          self.toldEvict = true;
                          "You tell her the manager at the trailer park found out a friend is living there.^
                          ^~Yes. I can see you are troubled. I can help. And only for a dollar.~";
                      'tom':
                          if (mapleRoad.firstTime) "~What about him? Vhy are you troubled by that?~";
                          "You tell her Toms freaking out down the street.^
                          ^~Oh. I see. You bring trouble vherever you go.~";
                      'nick', 'mark':
                          "~Vut? I don't know about him.~";
                      'amy':
                          "~Vut? I don't know about her.~";
                      'god':
                          "~Do not take the Lord's name in vain.~";
                      'satan', 'devil', 'hell':
                          "~Do not speak such blasphemies in my house.~";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "~Are you trouble by it? Pay me a dollar and I vill see if it's in your future.~";
                      default:
                          "~Vut? I don't know about that.~";
                  }
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              Give:
                  if (noun == crystalBall) return MadameSorraTakeBall();
                  if (noun == madameSorrasAfghan) {
                      "~I'm not giving you this. It's cold enough.~";
                  }
                  Strong: "The fortune teller ignores you.";
          ],
          nameFirstTime false,
          askForReading false,
          dontKillAskForReading false,
          spiritsRestless false,
          dontKillSpiritsRestless false,
          askAboutCrystal false,
          askAboutReading false,
          askAboutCity false,
          askSpringfield false,
          toldEvict false,
    has   animate female concealed proper;

  [ OldSorraResponse;
        "~I'm old and tired. Vhy are you concerned about that?~";
  ];

  [ OldSorraReading;
        if (oldMadameSorra.askAboutReading) "~I do readings for a dollar and vill show you the future.~";
        oldMadameSorra.askAboutReading = true;
        "~Yes. I have much practice in reading others. I vus taught how to scry and see into the future. I do readings for only a dollar.~";
  ];

  [ AskForNameOldSorra;
        if (oldMadameSorra.nameFirstTime) "~Please. Don't make me repeat it again.~";
        oldMadameSorra.nameFirstTime = true;
        "~My name is Sorra. Madame Sorra,~ she says slowly with a thick accent.";
  ];
