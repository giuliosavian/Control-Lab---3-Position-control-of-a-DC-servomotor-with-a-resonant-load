  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nominal_tracking_augmentedState_REALTIME_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_P.sens
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_P.AQ
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.BQ
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 4;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.N_u
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 12;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.N_x
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 13;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.deg2rad
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 19;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.degs2rpm
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 20;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.rpm2rads
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 21;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.step_size
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 22;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_FinalValue
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 23;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_InitialValue
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 24;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.EncoderInput_InputFilter
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 25;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.EncoderInput_MaxMissedTicks
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 26;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogInput_MaxMissedTicks
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 27;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_MaxMissedTicks
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 28;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.EncoderInput_YieldWhenWaiting
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 29;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogInput_YieldWhenWaiting
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 30;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_YieldWhenWaiting
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 31;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.IntervalTest_lowlimit
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 32;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.IntervalTest_lowlimit_k
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 33;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.IntervalTest_uplimit
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 34;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.IntervalTest_uplimit_o
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogInput_Channels
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 3;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogInput_RangeMode
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 4;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 5;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogInput_VoltRange
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 6;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_VoltRange
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_P.Out_Y0
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.DiscreteTimeIntegrator_gainval
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.DiscreteTimeIntegrator_IC
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.uV_Y0
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 3;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.StateSpace_C
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 4;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.StateSpace_InitialCondition
	  section.data(6).logicalSrcIdx = 34;
	  section.data(6).dtTransOffset = 8;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Statefeedback_Gain
	  section.data(7).logicalSrcIdx = 35;
	  section.data(7).dtTransOffset = 9;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Saturation_UpperSat
	  section.data(8).logicalSrcIdx = 36;
	  section.data(8).dtTransOffset = 15;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Saturation_LowerSat
	  section.data(9).logicalSrcIdx = 37;
	  section.data(9).dtTransOffset = 16;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Step_Time
	  section.data(10).logicalSrcIdx = 38;
	  section.data(10).dtTransOffset = 17;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Step_Y0
	  section.data(11).logicalSrcIdx = 39;
	  section.data(11).dtTransOffset = 18;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Highpassfilter_A
	  section.data(12).logicalSrcIdx = 40;
	  section.data(12).dtTransOffset = 19;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Highpassfilter_C
	  section.data(13).logicalSrcIdx = 41;
	  section.data(13).dtTransOffset = 21;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Highpassfilter1_A
	  section.data(14).logicalSrcIdx = 42;
	  section.data(14).dtTransOffset = 23;
	
	  ;% nominal_tracking_augmentedState_REALTIME_P.Highpassfilter1_C
	  section.data(15).logicalSrcIdx = 43;
	  section.data(15).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nominal_tracking_augmentedState_REALTIME_B)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_B.th_h
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.volt2deg
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.degs2rpm
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.degs2rpm1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.th_b
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.Inputfeedforward
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.Statefeedforward
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.deg2rad1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 13;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.deg2rad2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.Sum_a
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.Saturation
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.x
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 17;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.DiscreteTimeIntegrator
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_B.AND_l
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nominal_tracking_augmentedState_REALTIME_B.HiddenBuf_InsertedFor_StatespaceController_at_inport_5
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nominal_tracking_augmentedState_REALTIME_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nominal_tracking_augmentedState_REALTIME_DW.AnalogInput_PWORK
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nominal_tracking_augmentedState_REALTIME_DW.AnalogOutput_PWORK
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% nominal_tracking_augmentedState_REALTIME_DW.Scope3_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% nominal_tracking_augmentedState_REALTIME_DW.TAQSigLogging_InsertedFor_Sum_at_outport_0_PWORK.AQHandles
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 9;
	
	  ;% nominal_tracking_augmentedState_REALTIME_DW.Scope_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_SubsysRanBC
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nominal_tracking_augmentedState_REALTIME_DW.Average_SubsysRanBC
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_MODE
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nominal_tracking_augmentedState_REALTIME_DW.Average_MODE
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 38320141;
  targMap.checksum1 = 2484223919;
  targMap.checksum2 = 160616621;
  targMap.checksum3 = 389575484;

