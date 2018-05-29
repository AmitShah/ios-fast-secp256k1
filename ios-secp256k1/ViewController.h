//
//  ViewController.h
//  ios-secp256k1
//
//  Created by Amit Shah on 2018-05-29.
//  Copyright © 2018 Amit Shah. All rights reserved.
//

#import <UIKit/UIKit.h>

static NSData *stripDataZeros(NSData *data) {
    const char *bytes = data.bytes;
    NSUInteger offset = 0;
    while (offset < data.length && bytes[offset] == 0) { offset++; }
    return [data subdataWithRange:NSMakeRange(offset, data.length - offset)];
}

//hexBytes expect utf8strin encoded bytes within byte boundary
static NSData * dataFromChar(const char * chars, int len){
    
    int i = 0;
    bool flag = false;
    if(len > 1 && len %2!=0){
        flag = true;
    }
    NSMutableData *data = [NSMutableData dataWithCapacity:len / 2];
    char byteChars[3] = {'\0','\0','\0'};
    unsigned long wholeByte;
    
    while (i < len) {
        if(flag){
            byteChars[0] = '0';
            byteChars[1] = chars[i++];
            wholeByte = strtoul(byteChars, NULL, 16);
            [data appendBytes:&wholeByte length:1];
            flag = false;
        }
        else{
            byteChars[0] = chars[i++];
            byteChars[1] = chars[i++];
            wholeByte = strtoul(byteChars, NULL, 16);
            [data appendBytes:&wholeByte length:1];
        }
    }
    //unsigned char *bytePtr = (unsigned char *)[data bytes];
    return data;
    
}

@interface ViewController : UIViewController


@end

