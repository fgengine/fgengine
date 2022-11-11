//
//  FGE
//

import Foundation
import CFGE

public extension String {
    
    struct Range {
        
        public var raw: fge_index_range_t
        
        public init(
            _ raw: fge_index_range_t
        ) {
            self.raw = raw
        }
        
        public init(
            lower: UInt,
            upper: UInt
        ) {
            self.raw = .init(
                lower: lower,
                upper: upper
            )
        }
        
    }
    
}

public extension String.Range {
    
    @inlinable
    var lower: UInt {
        self.raw.lower
    }
    
    @inlinable
    var upper: UInt {
        self.raw.upper
    }

    @inlinable
    var count: UInt {
        self.raw.upper - self.raw.lower
    }
    
}

extension String.Range : Equatable {
    
    public static func == (lhs: String.Range, rhs: String.Range) -> Bool {
        lhs.lower == rhs.lower && lhs.upper == rhs.upper
    }
    
}
