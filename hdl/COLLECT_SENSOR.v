module COLLECT_SENSOR
(
	input             CLK,
	input             RST,
	input             ICU_INT,
	input      [ 7:0] I2C_READ_DATA,
	input             I2C_READ_VALID,
	input             I2C_BUSY,
	output reg        I2C_READ_EN,
	output reg [15:0] GYRO_X,
	output reg [15:0] GYRO_Y,
	output reg [15:0] GYRO_Z,
	output reg [15:0] ACCEL_X,
	output reg [15:0] ACCEL_Y,
	output reg [15:0] ACCEL_Z,
	output reg        GYRO_X_VALID,
	output reg        GYRO_Y_VALID,
	output reg        GYRO_Z_VALID,
	output reg        ACCEL_X_VALID,
	output reg        ACCEL_Y_VALID,
	output reg        ACCEL_Z_VALID
);

reg [3:0] ICU_INT_dl;
reg I2C_READ_VALID_dl;
reg I2C_BUSY_dl;
reg [3:0] bytes;

always @ (posedge CLK, posedge RST) begin
	if (RST) begin
		ICU_INT_dl <= 0;
		I2C_READ_VALID_dl <= 0;
		I2C_BUSY_dl <= 0;
		I2C_READ_EN <= 0;
		bytes <= 0;
		ACCEL_X <= 0;
		ACCEL_Y <= 0;
		ACCEL_Z <= 0;
		GYRO_X <= 0;
		GYRO_Y <= 0;
		GYRO_Z <= 0;
	end else begin
		ICU_INT_dl <= {ICU_INT_dl[2:0],ICU_INT};
		I2C_READ_VALID_dl <= I2C_READ_VALID;
		I2C_BUSY_dl <= I2C_BUSY;
		
		// I2C_READ_EN
		if (~ICU_INT_dl[3] && ICU_INT_dl[2])
			I2C_READ_EN <= 1;
		else if (I2C_BUSY_dl && ~I2C_BUSY)
			I2C_READ_EN <= 0;
		
		// bytes
		if (~ICU_INT_dl[3] && ICU_INT_dl[2])
			bytes <= 0;
		else if (~I2C_READ_VALID_dl && I2C_READ_VALID)
			bytes <= bytes + 4'd1;
		
		// GYRO and ACCEL values
		if (~I2C_READ_VALID_dl && I2C_READ_VALID) begin
			case (bytes)
				4'd0 : ACCEL_X[15:8] <= I2C_READ_DATA;
				4'd1 : ACCEL_X[ 7:0] <= I2C_READ_DATA;
				4'd2 : ACCEL_Y[15:8] <= I2C_READ_DATA;
				4'd3 : ACCEL_Y[ 7:0] <= I2C_READ_DATA;
				4'd4 : ACCEL_Z[15:8] <= I2C_READ_DATA;
				4'd5 : ACCEL_Z[ 7:0] <= I2C_READ_DATA;
				4'd8 : GYRO_X [15:8] <= I2C_READ_DATA;
				4'd9 : GYRO_X [ 7:0] <= I2C_READ_DATA;
				4'd10: GYRO_Y [15:8] <= I2C_READ_DATA;
				4'd11: GYRO_Y [ 7:0] <= I2C_READ_DATA;
				4'd12: GYRO_Z [15:8] <= I2C_READ_DATA;
				4'd13: GYRO_Z [ 7:0] <= I2C_READ_DATA;
			endcase
		end
		
		// GYRO and ACCEL valid
		if ((~I2C_READ_VALID_dl && I2C_READ_VALID) && (bytes == 4'd1))
			ACCEL_X_VALID <= 1;
		else
			ACCEL_X_VALID <= 0;
		if ((~I2C_READ_VALID_dl && I2C_READ_VALID) && (bytes == 4'd3))
			ACCEL_Y_VALID <= 1;
		else
			ACCEL_Y_VALID <= 0;
		if ((~I2C_READ_VALID_dl && I2C_READ_VALID) && (bytes == 4'd5))
			ACCEL_Z_VALID <= 1;
		else
			ACCEL_Z_VALID <= 0;
		if ((~I2C_READ_VALID_dl && I2C_READ_VALID) && (bytes == 4'd9))
			GYRO_X_VALID <= 1;
		else
			GYRO_X_VALID <= 0;
		if ((~I2C_READ_VALID_dl && I2C_READ_VALID) && (bytes == 4'd11))
			GYRO_Y_VALID <= 1;
		else
			GYRO_Y_VALID <= 0;
		if ((~I2C_READ_VALID_dl && I2C_READ_VALID) && (bytes == 4'd13))
			GYRO_Z_VALID <= 1;
		else
			GYRO_Z_VALID <= 0;
	end
end

endmodule