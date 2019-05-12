/*
 * PlayRtttl-lc.h
 *
 * Melodies and tunes moved to a separate file by Lee Cooper.
 *
 *  Copyright (C) 2018  Armin Joachimsmeyer
 *  armin.joachimsmeyer@gmail.com
 *
 *     Based on the RTTTL.pde example code written by Brett Hagman
 *     http://www.roguerobotics.com/
 *     bhagman@roguerobotics.com
 *
 *
 *  Original file is part of PlayRttl https://github.com/ArminJo/PlayRttl.  
 *  This repository is not longer working.  This file has been modified by 
 *  Lee Cooper and is now available at https://github.com/gleemon/RTTTL-LC
 *
 *  PlayRttl is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/gpl.html>.
 *
 *
 */

#ifndef SRC_PLAYRTTTL-LC_H_
#define SRC_PLAYRTTTL-LC_H_

#include <avr/pgmspace.h>
#include "pitches.h"

#define DEFAULT_DURATION 4
#define DEFAULT_OCTAVE 6
#define DEFAULT_BPM 63

void setTonePinIsInverted(bool aTonePinIsInverted);
void startPlayRtttl(uint8_t aTonePin, char *aRTTTLArrayPtr, void (*aOnComplete)()=NULL);
void playRtttlBlocking(uint8_t aTonePin, char *aRTTTLArrayPtr);

void startPlayRtttlPGM(uint8_t aTonePin, const char *aRTTTLArrayPtrPGM, void (*aOnComplete)()=NULL);
void playRtttlBlockingPGM(uint8_t aTonePin, const char *aRTTTLArrayPtrPGM);

void startPlayRandomRtttlFromArrayPGM(uint8_t aTonePin, const char* const aSongArrayPGM[], uint8_t aNumberOfEntriesInSongArrayPGM,
        char* aBufferPointer = NULL, uint8_t aBufferPointerSize = 0, void (*aOnComplete)()=NULL);
void playRandomRtttlBlocking(uint8_t aTonePin);

// To be called from loop. - Returns true if tone is playing, false if tone has ended or stopped
bool updatePlayRtttl(void);

void stopPlayRtttl(void);

void getRtttlNamePGM(const char *aRTTTLArrayPtrPGM, char * aBuffer, uint8_t aBuffersize);
void getRtttlName(char *aRTTTLArrayPtr, char * aBuffer, uint8_t aBuffersize);

void printNamePGM(const char *aRTTTLArrayPtrPGM);

struct playRtttlState {
    long MillisOfNextAction;
    const char * NextTonePointer;

    struct {
        uint8_t IsStopped :1;
        uint8_t IsPGMMemory :1;
        uint8_t IsTonePinInverted :1; // True if tone pin has inverted logic i.e. is active on low.
    } Flags;

    // Tone pin to use for output
    uint8_t TonePin;
    // Callback on completion of tone
    void (*OnComplete)(void);

    uint8_t DefaultDuration;
    uint8_t DefaultOctave;
    long TimeForWholeNoteMillis;
};

/*
 * RTTTL format:
 *  opt duration
 *  note
 *  opt dot to increase duration by half
 *  opt octave
 */
/*
 * Disclaimer: These ringtone melodies are for personal enjoyment only. All copyright belongs to its respective author.
 * comment/uncomment the following lines to determine which group of RingTones to include.
 */
#include <RingTones.h>
// #include <XmasTunes.h>


#endif /* SRC_PLAYRTTTL_H_ */
