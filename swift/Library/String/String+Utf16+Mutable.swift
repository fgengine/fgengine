//
//  FGE
//

import Foundation
import CFGE

public extension String.Utf16 {
    
    struct Mutable {
        
        public var raw: fge_utf16_pt
        
        @usableFromInline
        init(_ raw: fge_utf16_pt) {
            self.raw = raw
        }
        
    }
    
}

extension String.Utf16.Mutable : IUnsafeString {
    
    @inlinable
    public func unsafe< Result >(_ block: (OpaquePointer?, UInt) -> Result) -> Result {
        return block(OpaquePointer(fge_utf16_pointer(self.raw)), UInt(fge_utf16_count(self.raw)))
    }
    
}

extension String.Utf16.Mutable : IString {
    
    @inlinable
    public var capacity: UInt {
        .init(fge_utf16_capacity(self.raw))
    }
    
    @inlinable
    public var length: UInt {
        .init(fge_utf16_length(self.raw))
    }
    
    @inlinable
    public var count: UInt {
        .init(fge_utf16_count(self.raw))
    }
    
    @inlinable
    public var isEmpty: Bool {
        fge_utf16_is_empty(self.raw)
    }
    
    @inlinable
    public var isNotEmpty: Bool {
        fge_utf16_is_not_empty(self.raw)
    }
    
    @inlinable
    public var startIndex: UInt {
        .init(fge_utf16_start_index(self.raw))
    }
    
    @inlinable
    public var endIndex: UInt {
        .init(fge_utf16_end_index(self.raw))
    }
    
    @inlinable
    public var range: String.Range {
        .init(fge_utf16_range(self.raw))
    }
    
    @inlinable
    public func `is`< Equal : IUnsafeString >(equal: Equal) -> Bool {
        equal.unsafe({
            fge_utf16_is_equal(
                self.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    public func `is`< Prefix : IUnsafeString >(prefix: Prefix) -> Bool {
        prefix.unsafe({
            fge_utf16_is_prefix(
                self.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    public func `is`< Suffix : IUnsafeString >(suffix: Suffix) -> Bool {
        suffix.unsafe({
            fge_utf16_is_suffix(
                self.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    public func find< First : IUnsafeString >(first: First, in range: String.Range) -> String.Range {
        first.unsafe({
            .init(fge_utf16_find_start(
                self.raw,
                range.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            ))
        })
    }
    
    @inlinable
    public func find< Last : IUnsafeString >(last: Last, in range: String.Range) -> String.Range {
        last.unsafe({
            .init(fge_utf16_find_end(
                self.raw,
                range.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            ))
        })
    }

}

extension String.Utf16.Mutable : IMutableString {
    
    @inlinable
    public func clear() {
        fge_utf16_free(self.raw)
    }
    
    @inlinable
    @discardableResult
    public func fit() -> Bool {
        return fge_utf16_fit(self.raw)
    }
    
    @inlinable
    @discardableResult
    public func insert< Insert : IUnsafeString >(_ string: Insert, at index: UInt) -> Bool {
        string.unsafe({
            fge_utf16_insert(
                self.raw,
                index,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    @discardableResult
    public func prepend< Insert : IUnsafeString >(_ string: Insert) -> Bool {
        string.unsafe({
            fge_utf16_insert(
                self.raw,
                fge_utf16_start_index(self.raw),
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    @discardableResult
    public func append< Insert : IUnsafeString >(_ string: Insert) -> Bool {
        string.unsafe({
            fge_utf16_insert(
                self.raw,
                fge_utf16_end_index(self.raw),
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    @discardableResult
    public func remove(in range: String.Range) -> Bool {
        return fge_utf16_remove_range(self.raw, range.raw)
    }
    
    @inlinable
    @discardableResult
    public func remove< Search : IUnsafeString >(first: Search, in range: String.Range) -> Bool {
        first.unsafe({
            fge_utf16_remove_first(
                self.raw,
                range.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    @discardableResult
    public func remove< Last : IUnsafeString >(last: Last, in range: String.Range) -> Bool {
        last.unsafe({
            fge_utf16_remove_last(
                self.raw,
                range.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    @discardableResult
    public func remove< All : IUnsafeString >(all: All, in range: String.Range) -> UInt {
        all.unsafe({
            fge_utf16_remove_all(
                self.raw,
                range.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    @discardableResult
    public func replace< To : IUnsafeString >(range: String.Range, to: To) -> Bool {
        to.unsafe({
            fge_utf16_replace_range(
                self.raw,
                range.raw,
                .init(
                    ptr: fge_utf16_unit_cpt($0),
                    count: fge_sz_t($1)
                )
            )
        })
    }
    
    @inlinable
    @discardableResult
    public func replace< First : IUnsafeString, To : IUnsafeString >(first: First, to: To, in range: String.Range) -> Bool {
        first.unsafe({ firstPtr, firstSize in
            to.unsafe({ toPtr, toSize in
                fge_utf16_replace_first(
                    self.raw,
                    range.raw,
                    .init(
                        ptr: fge_utf16_unit_cpt(firstPtr),
                        count: fge_sz_t(firstSize)
                    ),
                    .init(
                        ptr: fge_utf16_unit_cpt(toPtr),
                        count: fge_sz_t(toSize)
                    )
                )
            })
        })
    }
    
    @inlinable
    @discardableResult
    public func replace< Last : IUnsafeString, To : IUnsafeString >(last: Last, to: To, in range: String.Range) -> Bool {
        last.unsafe({ lastPtr, lastSize in
            to.unsafe({ toPtr, toSize in
                fge_utf16_replace_last(
                    self.raw,
                    range.raw,
                    .init(
                        ptr: fge_utf16_unit_cpt(lastPtr),
                        count: fge_sz_t(lastSize)
                    ),
                    .init(
                        ptr: fge_utf16_unit_cpt(toPtr),
                        count: fge_sz_t(toSize)
                    )
                )
            })
        })
    }
    
    @inlinable
    @discardableResult
    public func replace< All : IUnsafeString, To : IUnsafeString >(all: All, to: To, in range: String.Range) -> UInt {
        all.unsafe({ allPtr, allSize in
            to.unsafe({ toPtr, toSize in
                fge_utf16_replace_all(
                    self.raw,
                    range.raw,
                    .init(
                        ptr: fge_utf16_unit_cpt(allPtr),
                        count: fge_sz_t(allSize)
                    ),
                    .init(
                        ptr: fge_utf16_unit_cpt(toPtr),
                        count: fge_sz_t(toSize)
                    )
                )
            })
        })
    }
    
}
