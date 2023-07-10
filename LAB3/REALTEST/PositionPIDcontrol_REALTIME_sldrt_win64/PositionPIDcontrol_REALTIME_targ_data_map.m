  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
    ;% Auto data (PositionPIDcontrol_REALTIME_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_P.sens
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_P.ctrl
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_P.deg2rad
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PositionPIDcontrol_REALTIME_P.step_size
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogOutput_FinalValue
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogOutput_InitialValue
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PositionPIDcontrol_REALTIME_P.EncoderInput_InputFilter
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PositionPIDcontrol_REALTIME_P.EncoderInput_MaxMissedTicks
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogInput_MaxMissedTicks
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogOutput_MaxMissedTicks
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PositionPIDcontrol_REALTIME_P.EncoderInput_YieldWhenWaiting
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogInput_YieldWhenWaiting
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogOutput_YieldWhenWaiting
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PositionPIDcontrol_REALTIME_P.IntervalTest_lowlimit
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% PositionPIDcontrol_REALTIME_P.IntervalTest_lowlimit_i
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% PositionPIDcontrol_REALTIME_P.IntervalTest_uplimit
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% PositionPIDcontrol_REALTIME_P.IntervalTest_uplimit_n
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogInput_Channels
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 3;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogInput_RangeMode
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 4;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 5;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogInput_VoltRange
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 6;
	
	  ;% PositionPIDcontrol_REALTIME_P.AnalogOutput_VoltRange
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_P.Out_Y0
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PositionPIDcontrol_REALTIME_P.DiscreteTimeIntegrator_gainval
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PositionPIDcontrol_REALTIME_P.DiscreteTimeIntegrator_IC
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PositionPIDcontrol_REALTIME_P.uV_Y0
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PositionPIDcontrol_REALTIME_P.RealDerivative_A
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PositionPIDcontrol_REALTIME_P.RealDerivative_C
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PositionPIDcontrol_REALTIME_P.RealDerivative_D
	  section.data(7).logicalSrcIdx = 30;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PositionPIDcontrol_REALTIME_P.Integrator_IC
	  section.data(8).logicalSrcIdx = 31;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PositionPIDcontrol_REALTIME_P.Saturation_UpperSat
	  section.data(9).logicalSrcIdx = 32;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PositionPIDcontrol_REALTIME_P.Saturation_LowerSat
	  section.data(10).logicalSrcIdx = 33;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PositionPIDcontrol_REALTIME_P.Step_Time
	  section.data(11).logicalSrcIdx = 34;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PositionPIDcontrol_REALTIME_P.Step_Y0
	  section.data(12).logicalSrcIdx = 35;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    ;% Auto data (PositionPIDcontrol_REALTIME_B)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_B.th_h
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PositionPIDcontrol_REALTIME_B.volt2deg
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PositionPIDcontrol_REALTIME_B.th_b
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PositionPIDcontrol_REALTIME_B.proportionalgain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PositionPIDcontrol_REALTIME_B.derivativegain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PositionPIDcontrol_REALTIME_B.pid_no_saturation
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PositionPIDcontrol_REALTIME_B.pid_output
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PositionPIDcontrol_REALTIME_B.Sum1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PositionPIDcontrol_REALTIME_B.K_w
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PositionPIDcontrol_REALTIME_B.integralgain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PositionPIDcontrol_REALTIME_B.Sum3
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PositionPIDcontrol_REALTIME_B.DiscreteTimeIntegrator
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_B.AND
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PositionPIDcontrol_REALTIME_B.HiddenBuf_InsertedFor_PIDController_at_inport_1
	  section.data(2).logicalSrcIdx = 13;
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
    ;% Auto data (PositionPIDcontrol_REALTIME_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PositionPIDcontrol_REALTIME_DW.AnalogInput_PWORK
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PositionPIDcontrol_REALTIME_DW.AnalogOutput_PWORK
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PositionPIDcontrol_REALTIME_DW.Scope1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PositionPIDcontrol_REALTIME_DW.TAQSigLogging_InsertedFor_Sum_at_outport_0_PWORK.AQHandles
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 5;
	
	  ;% PositionPIDcontrol_REALTIME_DW.Scope_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 6;
	
	  ;% PositionPIDcontrol_REALTIME_DW.Scope1_PWORK_j.LoggedData
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 8;
	
	  ;% PositionPIDcontrol_REALTIME_DW.TAQSigLogging_InsertedFor_Saturation_at_outport_0_PWORK.AQHandles
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 10;
	
	  ;% PositionPIDcontrol_REALTIME_DW.TAQSigLogging_InsertedFor_Sum_at_outport_0_PWORK_c.AQHandles
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_DW.PIDController_SubsysRanBC
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PositionPIDcontrol_REALTIME_DW.Average_SubsysRanBC
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PositionPIDcontrol_REALTIME_DW.PIDController_MODE
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PositionPIDcontrol_REALTIME_DW.Average_MODE
	  section.data(2).logicalSrcIdx = 13;
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


  targMap.checksum0 = 1050986377;
  targMap.checksum1 = 443537420;
  targMap.checksum2 = 1195580798;
  targMap.checksum3 = 213891046;

