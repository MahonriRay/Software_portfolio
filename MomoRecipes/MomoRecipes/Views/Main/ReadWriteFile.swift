//
//  ViewController.swift
//  MomoRecipes
//
//  Created by Mahonri Ray on 10/14/23.
//

import UIKit

class ReadWriteFile: UIViewController{
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        let fileName = "Test"
        let DocumentDirURL = try! FileManager.default.url(for: .documentDirectory, in: .userDomainMask, appropriateFor: nil, create: true)
        let fileURL = DocumentDirURL.appendingPathComponent(fileName).appendingPathExtension("txt")
        
        print("File Path: \(fileURL.path)")
        
        let writeString = "Write this text to the file in Swift"
        do{
            try writeString.write(to: fileURL, atomically: true, encoding: String.Encoding.utf8)
        } catch let error as NSError{
            print("Failed to write to URL ")
            print(error)
        }
        var readString = ""
        do {
            readString = try String(contentsOf: fileURL)
        } catch let error as NSError{
            print("Failed to read file")
            print(error)
        }
        
        print("Contents of the file \(readString)")
        
        let fileURLProject = Bundle.main.path(forResource: "Hello", ofType: "txt")
        var readStringProject = ""
        do {
            readStringProject = try String(contentsOfFile: fileURLProject!, encoding: String.Encoding.utf8)
        } catch let error as NSError{
            print("Failed to read from Project")
            print(error)
        }
        print(readStringProject)
    } 
}
