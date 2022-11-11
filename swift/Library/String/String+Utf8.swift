//
//  FGE
//

import Swift
import Foundation
import CFGE

public extension String {
    
    final class Utf8 {
        
        public var raw: fge_utf8_ct
        
        public init() {
            self.raw = fge_utf8()
        }
        
        public init(_ raw: fge_utf8_ct) {
            self.raw = raw
        }
        
        public init(move string: Utf8) {
            self.raw = string.raw
            string.raw = fge_utf8()
        }
        
        public init< Other : IUnsafeString >(_ other: Other) {
            self.raw = other.unsafe({
                fge_utf8_with(nil, .init(
                    ptr: fge_utf8_unit_cpt($0),
                    count: fge_sz_t($1)
                ))
            })
        }
        
        deinit {
            fge_utf8_free(&self.raw)
        }
        
    }
    
}

extension String.Utf8 : IUnsafeString {
    
    @inlinable
    public func unsafe< Result >(_ block: (OpaquePointer?, UInt) -> Result) -> Result {
        return block(OpaquePointer(fge_utf8_pointer(&self.raw)), UInt(fge_utf8_count(&self.raw)))
    }
    
}

extension String.Utf8 : IString {
    
    @inlinable
    public var capacity: UInt {
        .init(fge_utf8_capacity(&self.raw))
    }
    
    @inlinable
    public var length: UInt {
        .init(fge_utf8_length(&self.raw))
    }
    
    @inlinable
    public var count: UInt {
        .init(fge_utf8_count(&self.raw))
    }
    
    @inlinable
    public var isEmpty: Bool {
        fge_utf8_is_empty(&self.raw)
    }
    
    @inlinable
    public var isNotEmpty: Bool {
        fge_utf8_is_not_empty(&self.raw)
    }
    
    @inlinable
    public var startIndex: UInt {
        .init(fge_utf8_start_index(&self.raw))
    }
    
    @inlinable
    public var endIndex: UInt {
        .init(fge_utf8_end_index(&self.raw))
    }
    
    @inlinable
    public var range: String.Range {
        .init(fge_utf8_range(&self.raw))
    }
    
    @inlinable
    public func `is`< Equal : IUnsafeString >(equal: Equal) -> Bool {
        equal.unsafe({
            fge_utf8_is_equal(
                &self.raw,
                .init(
                    ptr: fge_utf8_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    public func `is`< Prefix : IUnsafeString >(prefix: Prefix) -> Bool {
        prefix.unsafe({
            fge_utf8_is_prefix(
                &self.raw,
                .init(
                    ptr: fge_utf8_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    public func `is`< Suffix : IUnsafeString >(suffix: Suffix) -> Bool {
        suffix.unsafe({
            fge_utf8_is_suffix(
                &self.raw,
                .init(
                    ptr: fge_utf8_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    public func find< First : IUnsafeString >(first: First, in range: String.Range) -> String.Range {
        first.unsafe({
            .init(fge_utf8_find_start(
                &self.raw,
                range.raw,
                .init(
                    ptr: fge_utf8_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            ))
        })
    }
    
    @inlinable
    public func find< Last : IUnsafeString >(last: Last, in range: String.Range) -> String.Range {
        last.unsafe({
            .init(fge_utf8_find_end(
                &self.raw,
                range.raw,
                .init(
                    ptr: fge_utf8_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            ))
        })
    }
    
}

public extension String.Utf8 {
    
    func modify(_ block: (_ mutable: Mutable) -> Void) {
        block(Mutable(&self.raw))
    }
    
    func copy(_ block: (_ mutable: Mutable) -> Void) -> Self {
        var copy = fge_utf8_with_string(self.raw.alloc, &self.raw)
        block(Mutable(&copy))
        return .init(copy)
    }
    
}
