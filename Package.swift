// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "FGE",
    platforms: [
        .iOS(.v10),
        .macOS(.v10_14)
    ],
    products: [
        .library(name: "FGE", type: .static, targets: [ "FGE" ])
    ],
    targets: [
        .target(
            name: "CFGE",
            path: "library",
            exclude: [ "test" ],
            sources: [ "src" ],
            publicHeadersPath: "inc"
        ),
        .target(
            name: "FGE",
            dependencies: [ .target(name: "CFGE") ],
            path: "swift/Library"
        ),
        .testTarget(
            name: "FGE-Test",
            dependencies: [ .target(name: "FGE") ],
            path: "swift/Test"
        )
    ],
    cLanguageStandard: .c2x
)
