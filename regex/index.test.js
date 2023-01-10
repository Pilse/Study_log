describe("기본 문자열 매칭", () => {
  test("hey 와 hey", () => {
    const regex = /hey/;
    expect("hey".match(regex)).toBeTruthy();
  });

  test("hey 와 they", () => {
    const regex = /hey/;
    expect("they".match(regex)).toBeTruthy();
  });
});

describe("수량 지정자 ?+*", () => {
  test("?는 0개 혹은 1개", () => {
    const regex = /he?y/;
    expect("hey".match(regex)).toBeTruthy();
    expect("hy".match(regex)).toBeTruthy();
  });

  test("+는 1개 이상", () => {
    const regex = /he+y/;
    expect("heeeeeeey".match(regex)).toBeTruthy();
    expect("hy".match(regex)).toBeFalsy();
  });

  test("*는 0개 이상", () => {
    const regex = /he*y/;
    expect("heeeeeeey".match(regex)).toBeTruthy();
    expect("hey".match(regex)).toBeTruthy();
    expect("hy".match(regex)).toBeTruthy();
  });
});

describe("와일드카드 .", () => {
  test(".는 어떤 문자도 가능", () => {
    const regex = /hey.*/;
    expect("hey!!".match(regex)).toBeTruthy();
    expect("hey?".match(regex)).toBeTruthy();
    expect("heyyyy!".match(regex)).toBeTruthy();
  });

  test(".는 '.'을 의미", () => {
    const regex = /hey\./;
    expect("hey.".match(regex)).toBeTruthy();
    expect("hey!!".match(regex)).toBeFalsy();
  });
});

describe("수량 범위 조절자 {}", () => {
  test("{3}은 오직 3개", () => {
    const regex = /hey{3}/;
    expect("heyyy".match(regex)).toBeTruthy();
    expect("heyy".match(regex)).toBeFalsy();
  });

  test("{1, 3}은 1~3개", () => {
    const regex = /hey{1,3}/;
    expect("heyy".match(regex)).toBeTruthy();
    expect("heyyy".match(regex)).toBeTruthy();
  });

  test("{2,}은 2이상", () => {
    const regex = /hey{2,}/;
    expect("heyy".match(regex)).toBeTruthy();
    expect("hey".match(regex)).toBeFalsy();
  });
});

describe("가능한 문자 모음 []", () => {
  test("[0123456789ABCDE]+ 로 16진수를 나타낼 수 있다", () => {
    const regex = /[0123456789ABCDE]+/;
    expect("C70".match(regex)).toBeTruthy();
    expect("ABCDE12".match(regex)).toBeTruthy();
    expect("NF14".match(regex)).toBeTruthy();
    expect("C0".match(regex)).toBeTruthy();
  });

  test("'-'를 이용한 범위 지정 [0-9A-F]", () => {
    const regex = /[0-9A-F]+/;
    expect("C70".match(regex)).toBeTruthy();
    expect("ABCDE12".match(regex)).toBeTruthy();
    expect("NF14".match(regex)).toBeTruthy();
    expect("C0".match(regex)).toBeTruthy();
  });

  test("'^'를 이용한 미포함 문자 지정", () => {
    const regex = /[A-Z][^\.?!]+[\.?!]/;
    expect("AB.".match(regex)).toBeTruthy();
    expect("A.a".match(regex)).toBeFalsy();
    expect("Do you want to get coffee with me".match(regex)).toBeFalsy();
    expect("Do you want to get coffee with me?".match(regex)).toBeTruthy();
  });
});

describe("whitespace 문자", () => {
  test("tab \\t", () => {
    const regex = /\t/;
    expect("	b".match(regex)).toBeTruthy();
  });

  test("space ' '", () => {
    const regex = / +.*/;
    expect(" hi".match(regex)).toBeTruthy();
  });
});

describe("시작, 끝 문자 ^$", () => {
  test("^는 시작 문자", () => {
    const regex = /^ /;
    expect(" hello world".match(regex)).toBeTruthy();
    expect("   hello world".match(regex)).toBeTruthy();
    expect("hello world".match(regex)).toBeFalsy();
  });

  test("$는 끝 문자", () => {
    const regex = /[A-Z][^\.!?]+[\.!?]$/;
    expect("This is a sentance.".match(regex)).toBeTruthy();
    expect("This is a sentance!".match(regex)).toBeTruthy();
    expect("This is a sentance! This is a sentance too.".match(regex)).toBeTruthy();
  });

  test("^ 와 $를 같이 사용하면 정교하여 매칭", () => {
    const regex = /^[A-Z][^\.!?]+[\.!?]$/;
    expect("This is a sentance! This is a sentance too.".match(regex)).toBeFalsy();
  });
});

describe("공백 문자 모음 \\s", () => {
  test("\\s를 사용하여 공백 매칭", () => {
    const regex = /^\s+/;
    expect("  ".match(regex)).toBeTruthy();
  });

  test("\\S = [^\\s] = [^\\r\\n\\t\\v\\f]", () => {
    const regex = /\S+/;
    expect("   ".match(regex)).toBeFalsy();
    expect("hi".match(regex)).toBeTruthy();
  });
});

describe("문자 모음", () => {
  test("\\d = [0-9]", () => {});
  test("\\D = [^0-9]", () => {});
  test("\\w = [0-9A-Za-z_]", () => {});
  test("\\W = [^0-9A-Za-z_]", () => {});

  test("\\b = \\w\\b\\W 혹은 \\W\\b\\w", () => {
    const regex = /\bstem\b/;
    expect("That rose has a lovely stem!".match(regex)).toBeTruthy();
    expect("Look at that solar system!".match(regex)).toBeFalsy();
  });

  test("\\B = \\w\\b\\W도 아니고 \\W\\b\\w도 아님", () => {
    const regex = /\Bstem\b/;
    expect("That rose has a lovely stem!".match(regex)).toBeFalsy();
    expect("Look at that solar system!".match(regex)).toBeTruthy();
  });

  test("\\b는 맨 앞 혹은 맨 뒤 문자열에도 사용 가능", () => {
    const regex = /\bstem\b/g;
    expect("stem stem stem".match(regex)).toHaveLength(3);
    expect("stem stem stem".match(regex)[0]).toEqual("stem");
  });
});

// 가능한 적은 문자
describe("lazy 역할의 수량조절자 '?'", () => {
  test("gre*? 은 gr까지만 매칭", () => {
    const regex = /gre*?/gim;
    expect("greedy".match(regex)[0]).toEqual("gr");
  });

  test("gre??은 gr까지만 매칭", () => {
    const regex = /gre??/gims;
    expect("greedy".match(regex)[0]).toEqual("gr");
  });

  test("gre+?은 gre까지만 매칭", () => {
    const regex = /gre+?/;
    expect("greedy".match(regex)[0]).toEqual("gre");
  });
});

describe("다문자 문자열 옵션 |", () => {
  test("kittens|foals|ducklings", () => {
    const regex = /kittens|foals|ducklings/;
    expect("I would like to adopt some kittens".match(regex)[0]).toEqual("kittens");
  });

  test("공백이 있어도 옵션 가능", () => {
    const regex = /I love kittens|foals|ducklings/;
    expect("I love kittens".match(regex)[0]).toEqual("I love kittens");
    expect("I love foals".match(regex)[0]).toEqual("foals");
  });
});

describe("그룹 ()", () => {
  test("문자열 옵션들 ", () => {
    const regex = /I love (kittens|foals|ducklings)/;
    expect("I love ducklings".match(regex)[0]).toEqual("I love ducklings");
  });

  test("특정 문자열 반복", () => {
    const regex = /(kittens)+/g;
    expect("I would like to adopt som kittenskittens kittens".match(regex)).toHaveLength(2);
    expect("I would like to adopt som kittenskittens kittens".match(regex)[0]).toEqual("kittenskittens");
  });
});

describe("그룹과 옵션 ()[]", () => {
  test("그룹 안의 옵션 ([])", () => {
    const regex = /(W[0O]W)+/;
    expect("WOW".match(regex)).toBeTruthy();
    expect("W0W".match(regex)).toBeTruthy();
    expect("WOWW0W".match(regex)).toBeTruthy();
    expect("WOOW".match(regex)).toBeFalsy();
  });
});

describe("그룹 캡쳐 ()", () => {
  test("파일 이름 캡쳐", () => {
    const regex = /(.+)\.(png|jpe?g|pdf)/;
    expect("cute_kittens.pdf".match(regex)[1]).toEqual("cute_kittens");
    expect("cute_kittens.wow.pdf".match(regex)[1]).toEqual("cute_kittens.wow");
    expect("cute_kittens.wow.pdf".match(regex)[2]).toEqual("pdf");
    expect("cute_kittens.wow.mpeg".match(regex)).toBeFalsy();
  });
});

describe("캡쳐 하지 않는 그룹 (?:)", () => {
  test("파일 이름만 캡쳐", () => {
    const regex = /(.+).(?:png|jpe?g|pdf)/;
    expect("cute_kittens.pdf".match(regex)[1]).toEqual("cute_kittens");
    expect("cute_kittens.wow.pdf".match(regex)[1]).toEqual("cute_kittens.wow");
    expect("cute_kittens.wow.pdf".match(regex)[2]).toBeFalsy();
    expect("cute_kittens.wow.mpeg".match(regex)).toBeFalsy();
  });
});

describe("numbered group", () => {
  test("html tag 이름이 같다", () => {
    const regex = /<(\w+)>.*?<\/\1>/;
    expect("<div>hello world</div>".match(regex)).toBeTruthy();
    expect("<div>hello world</span>".match(regex)).toBeFalsy();
  });
});

describe("named group", () => {
  test("named group을 통해 결과를 확인할 수 있다", () => {
    const regex = /(?<rootname>.+)\.(?<extension>png|jpe?g|pdf)/;
    expect("cute_kittens.pdf".match(regex).groups.rootname).toEqual("cute_kittens");
    expect("cute_kittens.pdf".match(regex).groups.extension).toEqual("pdf");
  });
});

describe("replace", () => {
  test("동물이름을 cute로 replace할 수 있다", () => {
    const regex = /kitten|puppy|piglet|foal|chick/g;
    const originText =
      "I brought home a kitten and a puppy yesterday. Then I went to the petting zoo and saw a piglet, a foal and a chick";
    const expectText =
      "I brought home a cute and a cute yesterday. Then I went to the petting zoo and saw a cute, a cute and a cute";
    expect(originText.replace(regex, "cute")).toEqual(expectText);
  });

  test("그룹을 지정하여 대체 할 수 있다", () => {
    const regex = /a (kitten|puppy|piglet|foal|chick)/g;
    const originText =
      "I brought home a kitten and a puppy yesterday. Then I went to the petting zoo and saw a piglet, a foal and a chick";
    const expectedText =
      "I brought home the cutest kitten and the cutest puppy yesterday. Then I went to the petting zoo and saw the cutest piglet, the cutest foal and the cutest chick";
    expect(originText.replace(regex, "the cutest $1")).toEqual(expectedText);
  });

  test("*_' '를 문장에서 제거할 수 있다", () => {
    const regex = /[*_" "]/g;
    const originText = "Now _this_ is a *workout* for your brain!";
    const expectedText = "Nowthisisaworkoutforyourbrain!";
    expect(originText.replace(regex, "")).toEqual(expectedText);
  });

  test("이메일을 가릴 수 있다.", () => {
    const regex = /^(\w+\.?)+@(\w+\.)+\w+$/gm;
    expect("gogosky1175@gmail.com".replace(regex, "<<redacted>>")).toEqual("<<redacted>>");
    expect("gogosky1175.office@uos.ac.kr".replace(regex, "<<redacted>>")).toEqual("<<redacted>>");
  });

  test("html 태그를 제거할 수 있다,", () => {
    const regex = /<(\w+)>(.*)<\/\1>/;
    expect("<div>hello world</div>".replace(regex, "$2")).toEqual("hello world");
    expect("<b>bold statement</b>".replace(regex, "$2")).toEqual("bold statement");
  });

  test("앞 뒤 공백을 제거할 수 있다", () => {
    const regex = /^\s+(.*?)\s+$/;
    expect("  this is a string    ".replace(regex, "$1")).toEqual("this is a string");
  });

  test("firstname과 lastname의 위치를 바꿀 수 있다", () => {
    const regex = /^\b([\w\-']+)\b\s+([\w\-']+)$/gim;
    expect("Indira Ghandi".replace(regex, "$2, $1")).toEqual("Ghandi, Indira");
  });

  test("firstname, middlename, lastname을 구분할 수 있다", () => {
    const regex = /^((?:[\w\-']+\s+)*)([\w\-']+)$/gim;
    expect("Harriet Beecher Stowe".replace(regex, "$2, $1")).toEqual("Stowe, Harriet Beecher ");
  });
});

describe("look around", () => {
  test("git 명령어만 추출할 수 있다", () => {
    const regex = /(?<=^(?:[\w\- ]+ git:\([\w\- ]+\) \$ )).+$/gm;
    expect("python git:(master) $ cd ~".match(regex)[0]).toEqual("cd ~");
  });

  test("meta__ 다음 문자열 만 추출할 수 있다", () => {
    const regex = /(?<=\bmeta__)\w+\b/gm;
    expect("a_tag, meta__another_tag, meta__third_tag, fourth_tag".match(regex)).toHaveLength(2);
    expect("a_tag, meta__another_tag, meta__third_tag, fourth_tag".match(regex)[0]).toEqual("another_tag");
    expect("a_tag, meta__another_tag, meta__third_tag, fourth_tag".match(regex)[1]).toEqual("third_tag");
  });

  test("파일 이름에 py를 가지고 .py 확장자를 가지지 않는 파일명을 추출할 수 있다", () => {
    const regex = /.*py.*(?<!py)$/;
    expect("happy.js".match(regex)[0]).toEqual("happy.js");
    expect("happy.py".match(regex)).toBeFalsy();
    expect("hello.js".match(regex)).toBeFalsy();
  });
});
