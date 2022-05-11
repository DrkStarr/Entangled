! Madame Sorra seems energized, almost youthful. Still, deep cracks line her face.
! ---------------------------------------------------------------------------- !
!       MADAME SORRA. 01/08/18
!
! Age: 63

  Object  madameSorrasMadameSorra "Madame Sorra"
    with  name 'madame' 'sorra' 'woman' 'lady' 'old' 'gypsy' 'sorrra' 'fortune-teller' 'fortune' 'teller',
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
                          return AskAboutNameSorra();
                      'palm', 'reading':
                          return MadameSorraReading();
                      'crystal', 'ball':
                          return MadameSorraTakeBall();
                      'change', 'quarters', 'quarter':
                          "~Vhy are you concerned? Are you looking to be rich?~";
                      'bill', 'dollar', 'buck':
                          if (self.seenHands)
                              "~I'm not giving it back. There's something vrong with you.
                              I did my part. You don't belong here.~";
                  }
                  return MadameSorraResponse();
              Examine:
                  "Clutching the afghan wrapped around her, the old lady sits hunched over in the corner
                  trying to stay warm from the fall weather creeping in. But the deep cracks you've seen before
                  are shallow, hands just beginning to knot with arthritis. She's old, but not ancient like you're used to seeing.";
              Search, Climb:
                  "I don't think she would care for that.";
              Talk:
                  print "[You can try ";
                  if (self.askAboutCity) {
                      print "ASK ABOUT CURATOR";
                  } else {
                      print "ASK ABOUT CITY";
                  }
                  print " or ";
                  if (self.askAboutReading) {
                      print "ASK ABOUT BALL";
                  } else {
                      print "ASK ABOUT READING";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  "~How can I help?~ she says, looking up from her ball.";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              Rub, Touch, Pet:
                  "You don't want to touch her. That's creepy.";
              Kiss, SmellNoun:
                  "That's creepy.";
              WaveObject:
                  "~Yes. I see your hands, but you need to show me them.";
              Take:
                  "You know she's not an object?";
              Push, Pull:
                  "~I'm old. Quit messing around.~";
          ],
          life [ w1;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: if(self.askForReading) "~Vut do you hope to find? Show me your hands so that I may know your future.~";
                             "~Hmm. I vill ponder that.~";
                      t_no: if (self.spiritsRestless) self.dontKillSpiritsRestless = true;
                            self.spiritsRestless = true;
                            "~You make the spirits restless.~";
                      t_good: "~Then share your vell being.~";
                      t_bad: "~Yes. I see a dark horizon.~";
                      t_sorry: if (self.spiritsRestless) "~Mere verds vill not quiet them down.~";
                               "~Is your guilt overcoming you?~";
                      t_thanks:
                          if (self.seenHands) "~You are a strange bird. Indeed.~";
                          "~It is my way. I try to help.~";
                      default:
                          return (MadameSorraResponse());
                  }
              Ask:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'halloween', 'samhain':
                          "~Samhain approaches. And vith it, spirits vill try to enter the living. I can tell you this for free. There is no vay to protect yourself.~";
                      'candy':
                          "~I do not eat such poison.~";
                      'arthritis':
                          "~I feel it creeping in. I am sure my days are numbered.~";
                      'sign', 'symbol':
                          "~Yes. I display it to attract customers. It brought you in.~";
                      'ball', 'crystal':
                          if (self.askAboutCrystal) "~Like I said. This vus my mother's.~";
                          self.askAboutCrystal = true;
                          "~This crystal ball vus my mother's. God rest her soul. It has been in my
                          family for many generations. Handed down from one to the next. But I have
                          no one to pass it on to.~";
                      'bill', 'dollar', 'buck':
                          if (self.seenHands)
                              "~There's something vrong about you. I can't see your future.~";
                          "~I charge a dollar for my readings. A fair price for a rare gift.~";
                      'name':
                          return AskAboutNameSorra();
                      'work', 'job', 'shop', 'place':
                          "~My family has done this for generations. But I'm the last in a long line.
                          I have no one to pass it on to. It dies vith me.~";
                      'scarf', 'babushka', 'headscarf', 'stole', 'muffler', 'tippet', 'kerchief', 'bandanna', 'possession', 'possessions':
                          "~Yes, I lost my babushka a v'ile back. I'm sure that snake in the park stole it.
                          My mother gave it to me. God rest her soul.~";
                      'satan':
                          "~Do not speak your blasphemy here.~";
                      'mother':
                          "~She came from the motherland, Romania, and vus a powerful scryer. She could read
                          the future and always knew what I vus up to. Taught me how to see using the ball
                          and gave me her scarf as a reminder of where we come from.~";
                      'romania', 'motherland':
                          "~Ah, yes, the motherland. I vill probably never make it back now. Old bones don't
                          move well.~";
                      'scry', 'scrying':
                          if (self.seenHands)
                              "~My gifts have never failed me before. But I can't explain vhy you are here.~";
                          if (self.askForReading) self.dontKillAskForReading = true;
                          self.askForReading = true;
                          "~I read the future. It's called scrying. It's vut I do. Looking for a reading yourself?~";
                      'spirit', 'spirits':
                          "~Spirits surround this place. Surround this town. They talk to me at night, showing me things clearly.~";
                      'city', 'town', 'sunnybrook':
                          self.askAboutCity = true;
                          "~It's a cold place. I've lived here too long, and I vant to retire.
                          Plus, there's Sarah. Hmm. Vhy are all the people here so cold?~";
                      'current', 'date', 'year':
                          "~Vhy are you so troubled by it?~";
                      'palm', 'reading', 'readings', 'help':
                          return MadameSorraReading();
                      'life', 'line', 'lifeline':
                          if (self.seenHands) {
                              "~Everybody has a lifeline. It's one of the three major lines.
                              Along vith the head and the heart. It's strange that you don't have one.~";
                          }
                          if (self.askForReading) self.dontKillAskForReading = true;
                          self.askForReading = true;
                          "~Vut about your lifeline? Do you vaunt a reading?~";
                      'hand', 'hands':
                          if (self.seenHands) {
                              "~Everybody has a lifeline. It's one of the three major lines.
                              Along vith the head and the heart. It's strange that you don't have one.~";
                          }
                          if (self.askForReading) self.dontKillAskForReading = true;
                          self.askForReading = true;
                          "~Vut about your hands? Do you vaunt a reading?~";
                      'fortune':
                          if (self.seenHands)
                              "~Your fortune is as ill fated as your future. You don't belong here.~";
                          "~I only ask a dollar so that you may know your fortune.
                          A small amount to pay to understand how things shall unfold.~";
                      'future', 'self':
                          if (self.seenHands)
                              "~Your future is more troubled than you know. You don't belong here.
                              The longer you stay will only unravel things.~";
                          "~Yes. Give a dollar and I vill tell you your future. Your path is clouded.
                          I have the guidance you need.~";
                      'guidance':
                          if (self.seenHands)
                              "~You must leave, you do not belong. Only your choices can set things right.~";
                          "~I can only show you the vay. You must make your own choice after that.~";
                      'madame', 'sorra', 'sorrra', 'gypsy', 'herself', 'fortune-teller', 'fortune', 'teller', 'her' , 'woman', 'lady':
                          if (self.seenHands)
                              "~I come from a long line of scryers and can see you don't belong here.~";
                          "~I come from a long line of scryers. I can see you're out of place and could use my help.~";
                      'park':
                          "~I get out very rarely. The park is not far from here. But that snake is always around.
                          He ruins my sense of peace and steals my possessions.~";
                      'bum', 'ed', 'eddie', 'snake':
                          "~Yes - the bum that lives in the park. He is a spawn from Hell itself.
                          Vhenever I'm there, he asks for things. Thinks
                          I should give him money. I don't know vhy I go. I'm sure he stole my babushka.
                          I lost it a short vhile back.~";
                      'yukypah', 'heef':
                          "~Vhy are you concerned about him?~";
                      'statue', 'melville', 'melvill':
                          "~Vhy are you concerned about it?~";
                      'change', 'quarters', 'quarter':
                          "~Vhy are you concerned? Are you looking to be rich?~";
                      'bowling', 'alley', 'library', 'school', 'post', 'office', 'pharmacy', 'complex', 'high-rise', 'highrise', 'highland', 'towers', 'bus', 'apartment', 'apartments':
                          "~Vhy? It does not factor in your future.~";
                      'the', 'tavern', 'bar', 'gas', 'station', 'art', 'gallery':
                          "~Vhy? It shouldn't factor into your future.~";
                      'convenience', 'drug', 'store', 'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s', 'house', 'abandoned', 'dog', 'doberman', 'trailer', 'fate':
                          if (self.seenHands) "~Your future is clouded. No one knows your fate.~";
                          "~I vill need to do a reading first.~";
                      'plug', 'spark', 'sparkplug', 'vacuum', 'tube', 'tubes', 'shard', 'fuse':
                          "~Vhy vould an old lady like me know anything about that?~";
                      'curator', 'sarah', 'hippie':
                          if (self.askAboutSarah)
                              "~Stay away from that vitch. She only has her interests at heart.~";
                          self.askAboutSarah = true;
                          "~Sarah. The vitch that vaunts to steal my things. Don't
                          trust that one. She's got a forked tongue on her.~";
                      'nancy', 'punk', 'judy', 'amy', 'girl', 'mabel':
                          "~I do not know this person, vhy do you ask about her?~";
                      'phil', 'phill', 'harry', 'old', 'guy', 'nick', 'pretty', 'boy', 'doorman', 'mark', 'jerry', 'scientist', 'tom', 'bob':
                          "~I do not know this person, vhy do you ask about him?~";
                      'sam':
                          print "~I do not know this person. Vhy do you ask about him?";
                          return AskMultiAboutSam();
                      'bartender':
                          print "~I don't know this person. Are you craving a drink?";
                          if (self.seenHands) "~";
                          print " Let me see your hands.~";
                      'attendant', 'clerk':
                          print "~I don't know this person. Are you craving something you don't understand?";
                          if (self.seenHands) "~";
                          " Let me see your hands.~";
                      'power':
                          "~I come from a long line of fortune-tellers and can see deep into the future. Most don't believe and don't follow the path they are on.~";
                      'practice':
                          "~Long have I stared into this ball, daring to see things most men hide from. You have no idea what's on the other side.~";
                      'other', 'side', 'things':
                          "~I dare not speak such blasphemy.~";
                      'path':
                          "~Ve all walk one, but you seem out of sync.~";
                      'night', 'obstacle':
                          if (TestHaveTwoFinal()) "~You approach the end of your journey. Soon you will see how things unfold.~";
                          if (TestHaveOneObject()) "~You are well on your way to see how things unfold.~";
                          "~Your journey is just starting. Soon you will see how things unfold.~";
                      'gift':
                          "~Yes. This gift is rare. Some call it a curse, others a blessing.~";
                      'god':
                          "~Do not speak lightly of God. It is a commandment.~";
                      'devil':
                          "~Do not speak such blasphemies in my house.~";
                      'hell':
                          "~Do not blaspheme in my house.~";
                      'pass', 'passing':
                          "~Yes. My mother showed me the art, and now I look to pass it on. It's such a burden.~";
                      'me', 'self', 'yourself':
                          "~You are trouble in these dark times. I can see it around you. Something blocks your path.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      'time', 'machine', 'note', 'notes': "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      default:
                          return (MadameSorraResponse());
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          if(self.askForReading) "~Vut do you hope to find? Show me your hands so that I may know your future.~";
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
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'god':
                          "~Do not take the Lord's name in vain.~";
                      'satan', 'devil', 'hell':
                          "~Do not speak such blasphemies in my house.~";
                      'thanks', 'thank':
                          if (self.seenHands) "~You are a strange bird. Indeed.~";
                          "~It is my way. I try to help.~";
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
              Strong: "The fortune-teller ignores you.";
          ],
          askForBall false,
          askForReading false,
          askAboutCrystal false,
          dontKillAskForReading false,
          nameFirstTime false,
          seenHands false,
          spiritsRestless false,
          dontKillSpiritsRestless false,
          askAboutSarah false,
          askAboutReading false,
          askAboutCity false,
    has   animate female concealed proper;

  [ MadameSorraResponse;
        "~Vhy are you concerned about such a thing?~";
  ];

  [ MadameSorraTakeBall;
        if (basement.firstTime) "~This crystal ball has been in my family for longer than you've been alive. Vhy vould I give it to you?~";
        if (artGallery.brokeCat) "~You are not vorthy. You're a taker. I see it in your eyes.~";
        if (madameSorrasMadameSorra.askForBall) "~You know it's better to give than to receive.~";
        madameSorrasMadameSorra.askForBall = true;
        remove incense;
        remove smallParkEddie;
        move babushka to smallPark;
        if (dollarBill in smallPark) remove dollarBill;
        "~You seem awful pushy. Vut makes you think you're vorthy of such a prize?~";
  ];

  [ MadameSorraReading;
        if (madameSorrasMadameSorra.seenHands)
            "~I don't know vut to make of someone like you,~ she says staring into her crystal ball,
            ~No lifeline. Strange.~";
        if (madameSorrasMadameSorra.askAboutReading) "~I do readings for a dollar and vill show you the future.~";
        madameSorrasMadameSorra.askAboutReading = true;
        "~I have a gift, passed down from my mother who taught me how to scry and see into
        the future. I do a reading. It vill cost a dollar.~";
  ];

  [ AskAboutNameSorra;
        SelfPlayer.knowSorra = true;
        if (madameSorrasMadameSorra.nameFirstTime) "~Did you not hear the first time? Madame Sorra.~";
        madameSorrasMadameSorra.nameFirstTime = true;
        iPeople++;
        "~You can call me Madame Sorra,~ she says in a thick accent.";
  ];

  [ AskMultiAboutSam;
        iAskSam++;
        if (iAskSam > 2) {
            iAskSam = 0;
            "~^^Looks like Sam is nowhere to be found.";
        }
        "~";
  ];


! No Crystal Shard - Solved Every Puzzle
! Test Final Two Objects

  [ TestHaveTwoFinal iTest;
        iTest = 0;
        if (theTavernMarshall.removedVacuumTube) iTest++;
        if (junkYardTV.removedVacuumTube) iTest++;
        if (gasStationCar.removeSparkPlug) iTest++;
        if (shed.removeSparkPlug) iTest++;
        if (iTest >= 2) rtrue;
        rfalse;
  ];

  [ TestHaveOneObject;
        if (theTavernMarshall.removedVacuumTube) rtrue;
        if (junkYardTV.removedVacuumTube) rtrue;
        if (gasStationCar.removeSparkPlug) rtrue;
        if (shed.removeSparkPlug) rtrue;
        if (artGallery.brokeCat) rtrue;
        rfalse;
  ];
