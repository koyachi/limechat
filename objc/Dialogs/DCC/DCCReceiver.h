// Created by Satoshi Nakagawa.
// You can redistribute it and/or modify it under the Ruby's license or the GPL2.

#import <Foundation/Foundation.h>
#import "DCCFileTransferCell.h"


@interface DCCReceiver : NSObject
{
	id delegate;
	int uid;
	NSString* peerNick;
	NSString* host;
	int port;
	long long size;
	long long processedSize;
	int version;
	DCCFileTransferStatus status;
	NSString* error;
	NSString* path;
	NSString* fileName;
	NSString* downloadFileName;
	NSImage* icon;
	NSProgressIndicator* progressBar;
}

@property (nonatomic, assign) id delegate;
@property (nonatomic, assign) int uid;
@property (nonatomic, retain) NSString* peerNick;
@property (nonatomic, retain) NSString* host;
@property (nonatomic, assign) int port;
@property (nonatomic, assign) long long size;
@property (nonatomic, assign) long long processedSize;
@property (nonatomic, assign) int version;
@property (nonatomic, assign) DCCFileTransferStatus status;
@property (nonatomic, retain) NSString* error;
@property (nonatomic, retain) NSString* path;
@property (nonatomic, retain) NSString* fileName;
@property (nonatomic, retain) NSString* downloadFileName;
@property (nonatomic, retain) NSImage* icon;
@property (nonatomic, retain) NSProgressIndicator* progressBar;

- (void)open;
- (void)close;

@end


@interface NSObject (DCCReceiverDelegate)
- (void)dccReceiveOnOpen:(DCCReceiver*)sender;
- (void)dccReceiveOnClose:(DCCReceiver*)sender;
- (void)dccReceiveOnError:(DCCReceiver*)sender;
- (void)dccReceiveOnComplete:(DCCReceiver*)sender;
@end