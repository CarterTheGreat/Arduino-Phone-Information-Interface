package com.example.cdwli.lcddisplay;

import android.content.Context;

import java.util.Date;

public class CallReceiver extends CallListener {


    //SMS---------
    @Override
    protected void onIncomingSms()
    {
        //
        MainActivity.incomingSms();
    }


    //CALL------
    @Override
    protected void onIncomingCallReceived(Context ctx, String number, Date start)
    {
        //
        MainActivity.incomingCall(number);
    }

    @Override
    protected void onIncomingCallAnswered(Context ctx, String number, Date start)
    {
        //
        }

    @Override
    protected void onIncomingCallEnded(Context ctx, String number, Date start, Date end)
    {
        //
    }

    @Override
    protected void onOutgoingCallStarted(Context ctx, String number, Date start)
    {
        //
    }

    @Override
    protected void onOutgoingCallEnded(Context ctx, String number, Date start, Date end)
    {
        //
    }

    @Override
    protected void onMissedCall(Context ctx, String number, Date start)
    {
        //
    }

}