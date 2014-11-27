//
//  main.swift
//  DataStructure
//
//  Created by Shintaro Kaneko on 11/27/14.
//  Copyright (c) 2014 Shintaro Kaneko. All rights reserved.
//

import Foundation

public typealias LogPointer = UnsafeMutablePointer<Log>

public class Log: NSObject {
    public var next: LogPointer?
    private var author: String?
    private var email: String?
    private var message: String?
    private var date: NSDate?

    override public var hash: Int {
        return (self.author!.hash ^ self.email!.hash ^ self.message!.hash ^ self.date!.hash)
    }

    public init(author: String? = nil, email: String? = nil, message: String) {
        self.author = author ?? "Default User"
        self.email = email ?? "default@example.com"
        self.message = message
        self.date = NSDate()
    }

    public func append(author: String? = nil, email: String? = nil, message: String) -> Log {
        var logPtr = LogPointer.alloc(1)
        logPtr.memory = Log(author: author, email: email, message: message)
        self.next = logPtr
        return logPtr.memory
    }

}

extension Log: Printable {
    override public var description: String {
        let hexHash = NSString(format: "%x", self.hash)
        return "commit \(hexHash)\nAuthor: \(self.author!) <\(self.email!)>\nDate:   \(self.date!)\n\n\(self.message!)\n\n"
    }
}

let initialLog = Log(author: "kaneshin", email: nil, message: "Initial commit.")
initialLog
    .append(author: "kaneshin", email: "kaneshin0120@gmail.com", message: "Second commit.")
    .append(author: "Shintaro Kaneko", email: "shintaro.kaneko@eure.jp", message: "Third commit.")
    .append(author: "Shintaro Kaneko", email: "shintaro.kaneko@eure.jp", message: "4th commit.")
    .append(author: "Shintaro Kaneko", email: "shintaro.kaneko@eure.jp", message: "5th commit.")

println(initialLog)
var next = initialLog.next
while let logPtr = next {
    println(logPtr.memory)
    next = logPtr.memory.next
}
