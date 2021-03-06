module PPM2CODE
(
	input             CLK,
	input             RST,
	input             PPM,
	output reg [15:0] CODE,
	output reg        VALID
);

reg  [15:0] cnt;
reg  [ 3:0] PPM_dl;

always @ (posedge CLK, posedge RST) begin
	if (RST) begin
		cnt <= 0;
		PPM_dl <= 0;
		CODE <= 0;
		VALID <= 0;
	end else begin
		PPM_dl <= {PPM_dl[2:0],PPM};
		if (PPM_dl[3])
			cnt <= cnt + 16'd1;
		else
			cnt <= 0;
		if (PPM_dl[3] && ~PPM_dl[2]) begin
			CODE <= cnt;
			VALID <= 1;
		end else
			VALID <= 0;
	end
end

endmodule