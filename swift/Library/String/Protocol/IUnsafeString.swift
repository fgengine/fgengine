//
//  FGE
//

import Foundation

public protocol IUnsafeString {
    
    func `unsafe`< Result >(_ block: (OpaquePointer?, UInt) -> Result) -> Result
    
}

extension Swift.String : IUnsafeString {
    
    @inlinable
    public func unsafe< Result >(_ block: (OpaquePointer?, UInt) -> Result) -> Result {
        self.withCString({
            block(OpaquePointer($0), UInt(self.count))
        })
    }
    
}

extension Swift.StaticString : IUnsafeString {
    
    @inlinable
    public func unsafe< Result >(_ block: (OpaquePointer?, UInt) -> Result) -> Result {
        self.withUTF8Buffer({
            block($0.baseAddress.flatMap({ OpaquePointer($0) }), UInt($0.count))
        })
    }
    
}
