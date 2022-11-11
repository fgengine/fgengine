//
//  FGE-Test
//

import XCTest
import FGE

class String : XCTestCase {
    
    func testInit() {
        do {
            let str = FGE.String.Utf8("Hello")
            if str.is(equal: "Hello") == false {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8("01234567")
            if str.is(equal: "01234567") == false {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8("0123456789")
            if str.is(equal: "0123456789") == false {
                XCTFail()
            }
        }
    }
    
    func testLength() {
        do {
            let str = FGE.String.Utf8("Hello world")
            if str.length != 11 {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8("Hello world ©")
            if str.length != 13 {
                XCTFail()
            }
        }
    }
    
    func testCheck() {
        do {
            let str = FGE.String.Utf8("Hello world")
            if str.is(prefix: "Hello") == false {
                XCTFail()
            }
            if str.is(suffix: "world") == false {
                XCTFail()
            }
        }
    }
    
    func testInsert() {
        do {
            let str = FGE.String.Utf8("world")
            str.modify({
                if $0.insert("Hello ", at: str.startIndex) == false {
                    XCTFail()
                }
            })
            if str.is(equal: "Hello world") == false {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8("Hello")
            str.modify({
                if $0.insert(" world", at: str.endIndex) == false {
                    XCTFail()
                }
            })
            if str.is(equal: "Hello world") == false {
                XCTFail()
            }
        }
    }
    
    func testRemove() {
        do {
            let str = FGE.String.Utf8("Hello  World  ")
            str.modify({
                if $0.remove(first: "  ") == false {
                    XCTFail()
                }
                if $0.fit() == false {
                    XCTFail()
                }
            })
            if str.is(equal: "HelloWorld  ") == false {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8("  Hello  World  ")
            str.modify({
                if $0.remove(first: "  ") == false {
                    XCTFail()
                }
                if $0.fit() == false {
                    XCTFail()
                }
            })
            if str.is(equal: "Hello  World  ") == false {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8("  Hello  World")
            str.modify({
                if $0.remove(last: "  ") == false {
                    XCTFail()
                }
                if $0.fit() == false {
                    XCTFail()
                }
            })
            if str.is(equal: "  HelloWorld") == false {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8("  Hello  World  ")
            str.modify({
                if $0.remove(last: "  ") == false {
                    XCTFail()
                }
                if $0.fit() == false {
                    XCTFail()
                }
            })
            if str.is(equal: "  Hello  World") == false {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8("  H e l l o  ")
            str.modify({
                if $0.remove(all: " ") == 0 {
                    XCTFail()
                }
                if $0.fit() == false {
                    XCTFail()
                }
            })
            if str.is(equal: "Hello") == false {
                XCTFail()
            }
        }
    }
    
    func testReplace() {
        do {
            let str = FGE.String.Utf8("Hello")
            str.modify({
                if $0.replace(range: $0.range, to: "World") == false {
                    XCTFail()
                }
                if $0.fit() == false {
                    XCTFail()
                }
            })
            if str.is(equal: "World") == false {
                XCTFail()
            }
        }
        do {
            let str = FGE.String.Utf8(" H e l l o  W o r l d ")
            str.modify({
                if $0.replace(all: " ", to: "-") == 0 {
                    XCTFail()
                }
                if $0.fit() == false {
                    XCTFail()
                }
            })
            if str.is(equal: "-H-e-l-l-o--W-o-r-l-d-") == false {
                XCTFail()
            }
        }
    }
    
    func testPerfomance() {
        self.measure({
            for _ in 0..<1000 {
                self.testInit()
                self.testLength()
                self.testCheck()
                self.testInsert()
                self.testRemove()
                self.testReplace()
            }
        })
    }
    
}
